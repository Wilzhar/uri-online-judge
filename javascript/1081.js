var input = require('fs').readFileSync('1081.txt', 'utf8');
var lines = input.split('\n');

var casesNumber = parseInt(lines[0]);

var finish = 0;

for (let i = 0; i < casesNumber; i++) {
    console.log(`Caso ${i + 1}:`);
    let vertexAndEdges = lines[finish + 1].split(" ")

    let vertex = parseInt(vertexAndEdges[0]);
    let edges = parseInt(vertexAndEdges[1]);

    let paths = {};

    for (let j = 0; j < edges; j++) {
        let edge = lines[j + finish + 2].split(" ");
        let start = edge[0];
        let end = parseInt(edge[1]);

        if (paths[start] == undefined) {
            paths[start] = [end];
        }
        else {
            let endNodes = paths[start];
            if (endNodes.find(endNode => endNode == end) == undefined) {
                insertElement(endNodes, end, 0, endNodes.length);
            }
            paths[start] = endNodes;

        }
    }

    let nodes = Object.keys(paths);

    let visitedNodes = [];

    for (let j = 0; j < nodes.length; j++) {
        if (visitedNodes.find(visitedNode => visitedNode == parseInt(nodes[j])) == undefined) {
            visitedNodes.push(parseInt(nodes[j]));
            generateTree(paths, visitedNodes, nodes[j], 1);
            console.log("");
        }
    }

    finish = finish + edges + 1;

}

function generateTree(paths, visitedNodes, node, depthLevel) {
    let spaces = "  ";
    let endNodes = paths[node];

    if (!(endNodes == undefined || endNodes.length <= 0)) {
        for (let k = 0; k < endNodes.length; k++) {
            if (visitedNodes.find(visitedNode => visitedNode == parseInt(endNodes[k])) == undefined) {
                console.log(`${spaces.repeat(depthLevel)}${node}-${endNodes[k]} pathR(G,${endNodes[k]})`);
                visitedNodes.push(endNodes[k]);
                generateTree(paths, visitedNodes, endNodes[k], depthLevel + 1);
            }
            else {
                console.log(`${spaces.repeat(depthLevel)}${node}-${endNodes[k]}`);
            }
        }
    }
}

function insertElement(list, element, start, finish) {

    if (finish - start == 0) {
        list.splice(start, 0, element);
        return list;
    }
    else if (finish - start == 1) {
        if (element < list[start]) {
            list.splice(start, 0, element);
        }
        else {
            list.splice(finish, 0, element);
        }
        return list;
    }
    else {

        if (element > list[start + Math.floor((finish - start) / 2)]) {
            insertElement(list, element, start + Math.floor((finish - start) / 2), finish);

        }
        else {
            insertElement(list, element, start, start + Math.floor((finish - start) / 2));
        }
    }
}