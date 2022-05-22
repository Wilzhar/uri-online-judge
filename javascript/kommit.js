var input = require('fs').readFileSync('kommit.txt', 'utf8');
var lines = input.split('\n');

// var nodesNumber = lines[0];

var edges = lines[0].trim().split(" ");

var graph = {};

var checkedNodes = [];

for (let i = 0; i < edges.length; i++) {
    addNode(edges[i]);
}

console.log(graph);

// removeNode("0");

console.log(isEdge("5", "8"));

function addNode(edge) {
    let nodes = edge.split(",");
    let startNode = nodes[0];
    let finishNode = nodes[1];

    if (!graph[startNode]) {
        graph[startNode] = [finishNode];
    }
    else {
        let finishNodes = graph[startNode];
        if (!finishNodes.find((currentNode) => currentNode == finishNode)) {
            finishNodes.push(finishNode);
            graph[startNode] = finishNodes;
        }
    }

    return graph;
}

function removeNode(node) {

    if (graph[node]) {
        delete graph[node];
    }

    let startNodes = Object.keys(graph);

    for (let i = 0; i < startNodes.length; i++) {
        let finishNodes = graph[startNodes[i]];
        for (let j = 0; j < finishNodes.length; j++) {
            if (finishNodes[j] == node) {
                finishNodes.splice(j, 1);
                j--;
            }
        }
    }

}

function isEdge(startNode, finishNode) {
    if (!graph[startNode]) {
        return false;
    }
    else {
        let finishNodes = graph[startNode];

        if (!checkedNodes.find(currentNode => currentNode == startNode)) {
            checkedNodes.push(startNode);
        }


        for (let i = 0; i < finishNodes.length; i++) {

            if (finishNodes[i] == finishNode) {
                return true;
            }

            if (!isCheckedNode(finishNodes[i])) {
                if (isEdge(finishNodes[i], finishNode)) {
                    return true;
                }
            }
        }

        return false;
    }
}

function isCheckedNode(node) {
    for (let i = 0; i < checkedNodes.length; i++) {
        if (checkedNodes[i] == node) {
            return true;
        }
    }
    return false;
}