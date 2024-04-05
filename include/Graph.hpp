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
				throw std::out_of_range("ERROR: Invalid start and/or end node(s)!");

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
				throw std::out_of_range("ERROR: Invalid start and/or end node(s)!");

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

		}

		// Method to remove a edge
		void remove_edge(const N& start, const N& end) {

		}

		// Method to get a edge
		// EDIT: Add exception if no edge
		E get_edge(const N& start, const N& dest) {

		}
	};
}

#endif