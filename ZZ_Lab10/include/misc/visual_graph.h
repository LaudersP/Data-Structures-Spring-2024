#pragma once
#include <array_list.h>
#include <text_circle.h>
#include <iostream>
#include <unordered_map.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <graph.h>
#include <fstream>
#include <string>
#include <array_list.h>
#include <queue.h>

namespace misc
{
	/// <summary>
	/// A VisualGraph that uses our generic GraphClass (and sf::TextCircle)
	/// </summary>
	class VisualGraph
	{
	protected:
		/// <summary>
		/// The font object to be used within the circles
		/// </summary>
		sf::Font mCircleFont;

		/// <summary>
		/// The Graph used to track connections between the nodes.  The Nodes are integers which correspond to
		/// an entry in mCircleData
		/// </summary>
		ssuds::Graph<int, float> mInternalGraph;

		/// <summary>
		/// Instead of storing the Node data in mInternalGraph, I chose to store it here, indexed by id# (this
		/// was mostly because I didn't want to create a hash function for text circle)
		/// </summary>
		ssuds::UnorderedMap<int, sf::TextCircle> mCircleData;

		/// <summary>
		/// Used to store the nodes selected
		/// </summary>
		ssuds::ArrayList<int> _selectedNodes;


	public:
		/// <summary>
		/// Main constructor
		/// </summary>
		/// <param name="circle_font">the font to be used withing node circles</param>
		/// <param name="status_font">the font to be used for status text</param>
		VisualGraph(const sf::Font& circle_font, const std::string& fname);

		/// <summary>
		/// A method to draw all things (the graph, the status text, etc.)
		/// </summary>
		/// <param name="Vector2f"></param>
		void draw(sf::RenderWindow& rw);

		/// <summary>
		/// Replaces the current graph with that loaded from fname
		/// </summary>
		/// <param name="fname">filename (and path info) to load</param>
		/// <returns></returns>
		void load(const std::string& fname);

		/// <summary>
		/// Checks if the passed cordinates of the moust click where on a node,
		/// if it was add it to an array for handling
		/// </summary>
		/// <param name="X"></param>
		/// <param name="Y"></param>
		/// <param name="end"></param>
		ssuds::ArrayList<int> handleMouseClick(const float X, const float Y, bool end = false);

		/// <summary>
		/// Calls the Breath First traversal to the internal graph of nodes
		/// </summary>
		/// <param name="traversalMap"></param>
		void breadthFirstTraversal(ssuds::ArrayList<std::pair<int, int>>& traversalMap);

		/// <summary>
		/// Calls the Depth First traversal to the internal graph of nodes
		/// </summary>
		/// <param name="traversalMap"></param>
		void depthFirstTraversal(ssuds::ArrayList<std::pair<int, int>>& traversalMap);
	};
}
