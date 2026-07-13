// Copyright (c) 2026 Christian Hinkle.

#include <Node.h>
#include <queue>
#include <unordered_map>
#include <functional>
#include <cassert>
#include <utility>

/**
 * Note: This implementation is based on depth-first search and recursion.
 */
class Solution
{
public:
    static Node* cloneGraph(Node* node);

private:
    static Node& cloneGraphImpl(const Node& sourceNode, std::unordered_map<const Node*, std::reference_wrapper<Node>>& sourceNodeToClonedNodeMap);
};

Node* Solution::cloneGraph(Node* node)
{
    if (!node)
    {
        return nullptr;
    }

    std::unordered_map<const Node*, std::reference_wrapper<Node>> sourceNodeToClonedNodeMap;
    Node& nodeCloned = cloneGraphImpl(*node, sourceNodeToClonedNodeMap);
    return &nodeCloned;
}

Node& Solution::cloneGraphImpl(const Node& sourceNode, std::unordered_map<const Node*, std::reference_wrapper<Node>>& sourceNodeToClonedNodeMap)
{
    // We made sure not to attempt to clone any nodes that were already cloned, so this shouldn't ever fail.
    assert(!sourceNodeToClonedNodeMap.contains(&sourceNode));

    Node* nodeClonedPtr = new Node{sourceNode.val};
    assert(nodeClonedPtr); // We require the free-store allocation to succeed.
    Node& nodeCloned = *nodeClonedPtr;

    // Note: It's important that we create and store this cloned node upfront, before recursing, or else we would get a stack overflow from
    // endlessly searching potential cycles in the graph.
    sourceNodeToClonedNodeMap.emplace(&sourceNode, nodeCloned);

    // Now, clone this node's neighboring nodes, while updating the cloned node's neighbors array in the process.
    for (Node* neighbor : sourceNode.neighbors)
    {
        if (!neighbor)
        {
            // I guess we'll just mimic the source array and push a null pointer here if this case hits.
            nodeCloned.neighbors.push_back(nullptr);
            continue;
        }

        Node* neighborCloned{};

        if (auto foundNeighborClonedIter = sourceNodeToClonedNodeMap.find(neighbor); foundNeighborClonedIter != sourceNodeToClonedNodeMap.end())
        {
            neighborCloned = &foundNeighborClonedIter->second.get();
        }
        else
        {
            Node& neighborClonedRef = cloneGraphImpl(*neighbor, sourceNodeToClonedNodeMap);
            neighborCloned = &neighborClonedRef;
        }

        nodeCloned.neighbors.push_back(neighborCloned);
    }

    return nodeCloned;
}
