#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <unordered_map>
#include <stdexcept>
#include <Array_List_v2.hpp>

namespace ssuds {
	template <class N, class E>
	/**
	* @brief A template class for creating and managing a graph data structure.
    * 
    * This class uses nested unordered maps to represent a graph, where each node
    * can be connected to other nodes with edges that have associated values.
	*/
	class Graph {
	protected:
		/**
		* @brief Stores the graph data.
		*/
		std::unordered_map<N, std::unordered_map<N, E>> _data;

	public:
		/**
		* @brief Adds a new node to the graph.
		*
		* If the node already exists, this function does nothing.
		*
		* @param val The value of the node to be added.
		*/
		void add_node(const N& val) {
			_data[val];
		}

		/**
		* @brief Adds an edge between two existing nodes.
		*
		* If either of the nodes does not exist, throws std::out_of_range.
		*
		* @param start_node The starting node of the edge.
		* @param dest_node The destination node of the edge.
		* @param val The value of the edge.
		*/
		void add_edge(const N& start_node, const N& dest_node, const E& val) {
			// Check that 'start_node' and 'dest_node' exist
			if (_data.find(start_node) == _data.end() || _data.find(dest_node) == _data.end())
				throw std::out_of_range("ERROR: Invalid start and/or dest nodes(s)!\n");

			_data[start_node][dest_node] = val;
		}
		
		/**
		* @brief Checks if a node exists in the graph.
		*
		* @param node The node to check.
		* @return True if the node exists, false otherwise.
		*/
		bool contains_node(const N& node) const {
			return _data.find(node) != _data.end();
		}

		/**
		* @brief Checks if an edge exists between two nodes.
		*
		* If either of the nodes does not exist, throws std::out_of_range.
		*
		* @param start_node The starting node of the edge.
		* @param end_node The ending node of the edge.
		* @return True if the edge exists, false otherwise.
		*/
		bool contains_edge(const N& start_node, const N& end_node) const {
			// Check that 'start_node' and 'dest_node' exist
			if (_data.find(start_node) == _data.end() || _data.find(end_node) == _data.end())
				throw std::out_of_range("ERROR: Invalid start and/or end node(s)!\n");

			typename std::unordered_map<N, std::unordered_map<N, E>>::const_iterator iter = _data.find(start_node);
			return iter->second.find(end_node) != iter->second.end();
		}

		/**
		* @brief Removes a node and all edges connected to it.
		*
		* If the node does not exist, throws std::out_of_range.
		*
		* @param node The node to remove.
		*/
		void remove_node(const N& node) {
			// Check that 'node' exists
			if (_data.find(node) == _data.end())
				throw std::out_of_range("ERROR: Invalid start node!\n");

			// Iterate through the edges
			for (typename std::unordered_map<N, std::unordered_map<N, E>>::iterator edge = _data.begin(); edge != _data.end(); ++edge) {
				edge->second.erase(node);
			}

			_data.erase(node);
		}

		/**
		* @brief Removes an edge between two nodes.
		*
		* If either node does not exist, or if the edge does not exist, throws std::out_of_range.
		*
		* @param start_node The start node of the edge to remove.
		* @param end_node The end node of the edge to remove.
		*/
		void remove_edge(const N& start_node, const N& end_node) {
			// Check that 'start_node' and 'dest_node' exist
			if (_data.find(start_node) == _data.end() || _data.find(end_node) == _data.end())
				throw std::out_of_range("ERROR: Invalid start and/or end node(s)!\n");

			std::unordered_map<N, E>& edges = _data[start_node];

			// Check that removing node was sucessful
			if (edges.erase(end_node) == 0)
				throw std::out_of_range("ERROR: Edge does not exist!\n");
		}

		/**
		* @brief Gets the value of an edge between two nodes.
		*
		* If either node does not exist, or if the edge does not exist, throws std::out_of_range.
		*
		* @param start_node The start node of the edge.
		* @param dest_node The destination node of the edge.
		* @return The value of the edge.
		*/
		E get_edge(const N& start_node, const N& dest_node) {
			// Check that 'start_node' and 'dest_node' exist
			if (_data.find(start_node) == _data.end() || _data.find(dest_node) == _data.end())
				throw std::out_of_range("ERROR: Invalid start and/or dest node(s)!\n");

			std::unordered_map<N, E>& edges = _data[start_node];
			typename std::unordered_map<N, E>::iterator edge_iter = edges.find(dest_node);

			// Check for a valid iter
			if (edge_iter != edges.end())
				return edge_iter->second;
			else
				throw std::out_of_range("ERROR: Edge does not exist!\n");
		}

		/**
		* @brief Overloads the output stream operator to print the graph's contents.
		*
		* Iterates through each node and its edges, printing them in a readable format.
		*
		* @param os The output stream.
		* @param graph The graph to print.
		* @return The output stream.
		*/
		friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
			// Iterate through the nodes
			for (const auto& node_iter : graph._data) {
				os << node_iter.first << " |";
				const auto& edges = node_iter.second;

				// Iterate through the edges
				for (const auto& edge_iter : edges) {
					os << " (" << edge_iter.first << ":" << edge_iter.second << ")";
				}
				os << "\n";
			}

			return os;
		}

		/**
		* @brief Allows the user to get the complete graph's edges as an array
		* 
		* @return the array version of the graph
		*/
		ssuds::ArrayListV2 <std::tuple<N, N, E>> get_all_edges() const {
			ssuds::ArrayListV2<std::tuple<N, N, E>> edge_list;

			// Iterate through the nodes
			for (const auto& node_iter : _data) {
				// Iterate through the edges
				for (const auto& edge_iter : node_iter.second) {
					edge_list.Append(std::make_tuple(node_iter.first, edge_iter.first, edge_iter.second));
				}

			}

			return edge_list;
		}
	};
}

#endif