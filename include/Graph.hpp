#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <UnorderedHashMap.hpp>

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
		ssuds::UnorderedMap<N, ssuds::UnorderedMap<N, E>> _data;

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
			if (!_data.contains(start_node) || !_data.contains(dest_node))
				throw std::out_of_range("ERROR: Invalid start and/or dest node(s)!\n");

			_data[start_node][dest_node] = val;
			return;
		}
		
		/**
		* @brief Checks if a node exists in the graph.
		*
		* @param node The node to check.
		* @return True if the node exists, false otherwise.
		*/
		bool contains_node(const N& node) const {
			return _data.contains(node);
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
			if (!_data.contains(start_node) || !_data.contains(end_node))
				throw std::out_of_range("ERROR: Invalid start and/or end node(s)!\n");

			typename ssuds::UnorderedMap<N, ssuds::UnorderedMap<N, E>>::UnorderedMapIterator iter = _data.find(start_node);

			// Check for valid iterator
			if (iter != _data.end()) {
				const ssuds::UnorderedMap<N, E>& edges = (*iter).second;
				return edges.contains(end_node);
			}

			return false;
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
			if(!_data.contains(node))
				throw std::out_of_range("ERROR: Invalid start node!\n");

			for (auto& pair : _data) {
				if (pair.second.contains(node)) {
					typename ssuds::UnorderedMap<N, E>::UnorderedMapIterator edge_iter = pair.second.find(node);
					if (edge_iter != pair.second.end())
						pair.second.remove(edge_iter);
				}
			}
				
			typename ssuds::UnorderedMap<N, ssuds::UnorderedMap<N, E>>::UnorderedMapIterator node_iter = _data.find(node);
			if (node_iter != _data.end())
				_data.remove(node_iter);
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
			if (!_data.contains(start_node) || !_data.contains(end_node))
				throw std::out_of_range("ERROR: Invalid start and/or end node(s)!\n");

			// Check that the edge exists
			if (!_data[start_node].contains(end_node))
				throw std::out_of_range("ERROR: Edge does not exist!\n");

			ssuds::UnorderedMap<N, E>& edges = _data[start_node];
			typename ssuds::UnorderedMap<N, E>::UnorderedMapIterator edge_iter = edges.find(end_node);
			// Check that 'end_node' was properly found
			if (edge_iter != edges.end())
				edges.remove(edge_iter);
			else
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
			if (!_data.contains(start_node) || !_data.contains(dest_node))
				throw std::out_of_range("ERROR: Invalid start and/or dest node(s)!\n");

			ssuds::UnorderedMap<N, E>& edges = _data[start_node];
			if (edges.contains(dest_node))
				return edges[dest_node];
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
			for (auto node_iter = graph._data.begin(); node_iter != graph._data.end(); ++node_iter) {
				const auto& node = *node_iter;

				os << node.first << " |";
				const ssuds::UnorderedMap<N, E>& edges = node.second;

				// Iterate through the edges
				for (auto edge_iter = edges.begin(); edge_iter != edges.end(); ++edge_iter) {
					const auto& edge = *edge_iter;

					os << " (" << edge.first << ":" << edge.second << ")";
				}
				os << "\n";
			}

			return os;
		}
	};
}

#endif