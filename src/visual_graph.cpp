#include <visual_graph.h>

misc::VisualGraph::VisualGraph(const sf::Font& circle_font, const std::string& fname) : mCircleFont(circle_font) {
	load(fname);
}
	
void misc::VisualGraph::draw(sf::RenderWindow& rw) {
	// Draw edges
	sf::VertexArray lines(sf::LinesStrip, 2);
	ssuds::UnorderedMap<int, ssuds::UnorderedMap<int, float>>::UnorderedMapIterator outer_it = mInternalGraph.begin();
	while (outer_it != mInternalGraph.end()) {
		ssuds::UnorderedMap<int, float>::UnorderedMapIterator inner_it = (*outer_it).second.begin();
		while (inner_it != (*outer_it).second.end()) {
			std::pair<int, float> p = *inner_it;

			// See if this is a bi-directional edge or not
			bool bidirectional = false;
			ssuds::UnorderedMap<int, ssuds::UnorderedMap<int, float>>::UnorderedMapIterator test_it = mInternalGraph.find(p.first);
			if (test_it != mInternalGraph.end()) {
				ssuds::UnorderedMap<int, float>::UnorderedMapIterator test_it2 = (*test_it).second.find((*outer_it).first);
				if (test_it2 != (*test_it).second.end())
					bidirectional = true;
			}
			if (bidirectional)
				lines[0].color = lines[1].color = sf::Color::White;
			else {
				lines[0].color = sf::Color(0u, 0u, 255u, 255u);
				lines[1].color = sf::Color::White;
			}
			lines[0].position = mCircleData[(*outer_it).first].get_position();
			lines[1].position = mCircleData[p.first].get_position();
			rw.draw(lines);
			++inner_it;
		}
		++outer_it;
	}

	for (std::pair<int, sf::TextCircle>& pair : mCircleData) {
		pair.second.set_highlight(sf::TextCircleHighlightMode::NONE);

		if (_selectedNodes.size() > 0) {
			// Check if the node is selected
			if (_selectedNodes.find(pair.first) != -1)
				pair.second.set_highlight(sf::TextCircleHighlightMode::WHITE);
		}
		
		rw.draw(pair.second);
	}
}

void misc::VisualGraph::load(const std::string& fname) {
	// Clear out any existing data
	mInternalGraph.clear();
	mCircleData.clear();

	std::ifstream fp(fname);
	if (fp.is_open()) {
		while (true) {
			std::string datatype;
			std::getline(fp, datatype, ':');
			if (fp.eof())
				break;
			if (datatype == "n") {
				// Format=>     n:id:name:red:green:blue:x:y
				int red, green, blue;
				float x, y;
				int id;
				std::string name;
				fp >> id;
				std::getline(fp, name, ':');		// Consumes the ':'
				std::getline(fp, name, ':');
				fp >> red;
				fp.ignore(1);
				fp >> green;
				fp.ignore(1);
				fp >> blue;
				fp.ignore(1);
				fp >> x;
				fp.ignore(1);
				fp >> y;
				fp.ignore(1);
				mCircleData[id] = sf::TextCircle(x, y, mCircleFont, name);
				mCircleData[id].setCircleColor(sf::Color((sf::Uint8)red, (sf::Uint8)green, (sf::Uint8)blue));
				mInternalGraph.add_node(id);
			}
			else if (datatype == "e") {
				// Format=>     e:id_start:id_end:edge_value
				float d;
				int id_start, id_end;
				fp >> id_start;
				fp.ignore(1);
				fp >> id_end;
				fp.ignore(1);
				fp >> d;
				fp.ignore(1);
				if (mInternalGraph.contains_node(id_start) && mInternalGraph.contains_node(id_end))
					mInternalGraph.set_edge(id_start, id_end, d);
			}
		}
	}
}

ssuds::ArrayListV2<int> misc::VisualGraph::handleMouseClick(const float X, const float Y, bool end) {
	unsigned int nodeCount;

	// Check if both the start and end node are wanted
	if (end)
		nodeCount = 2;
	// Only start node is needed
	else
		nodeCount = 1;

	// Iterate through each node to check if the click was on that node
	for (std::pair<int, sf::TextCircle>& pair : mCircleData) {
		sf::Vector2f node_position = pair.second.get_position();
		float radius = pair.second.get_radius();
		float distance = std::hypot(node_position.x - X, node_position.y - Y);

		// Check if the click is directly on the node
		if (distance <= radius) {
			int idx;

			// Check if there are selected nodes
			if (_selectedNodes.size() > 0)
				idx = _selectedNodes.find(pair.first);
			else
				idx = -1;

			// Check if it is already selected
			if (idx != -1)
				_selectedNodes.remove(idx);
			else {
				// Select the node if less than 1 nodes are already selected
				if (_selectedNodes.size() < nodeCount)
					_selectedNodes.append(pair.first);
			}
			break;
		}
	}

	return _selectedNodes;
}

void misc::VisualGraph::breadthFirstTraversal(ssuds::ArrayListV2<std::pair<int, int>>& traversalMap) {
	// Check that there is a start node
	if (_selectedNodes.size() == 0)
		throw std::out_of_range("ERROR: No start node was selected!\n");

	mInternalGraph.breadthFirst(traversalMap, _selectedNodes[0]);
}

void misc::VisualGraph::depthFirstTraversal(ssuds::ArrayListV2<std::pair<int, int>>& traversalMap) {
	// Check that there is a start node
	if (_selectedNodes.size() == 0)
		throw std::out_of_range("ERROR: No start node was selected!\n");

	mInternalGraph.depthFirst(traversalMap, _selectedNodes[0]);
}