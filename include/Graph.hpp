#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <UnorderedHashMap.hpp>

namespace ssuds {
	template <class N, class E>
	class Graph {
	protected:
		// Unordered hash map to store a map of node edges
		ssuds::UnorderedMap<N, ssuds::UnorderedMap<N, E>> _data;

	public:
		// Method to add a new node
		void add_node(const N& val) {
			_data[val];
		}

		// Method to add a connection between nodes
		void add_edge(const N& start_node, const N& dest_node, const E& val) {
			// Check that 'start_node' and 'dest_node' exist
			if (!_data.contains(start_node) || !_data.contains(dest_node))
				throw std::out_of_range("ERROR: Invalid start and/or dest node(s)!\n");

			_data[start_node][dest_node] = val;
			return;
		}
		
		// Method to check if a node exists
		bool contains_node(const N& node) const {
			return _data.contains(node);
		}

		// Method to check if a edge exists
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

		// Method to remove a node
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

		// Method to remove a edge
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

		// Method to get a edge
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