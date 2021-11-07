var input = require('fs').readFileSync('1195.txt', 'utf8');
var lines = input.split('\n');

var casesNumber = parseInt(lines[0]);

var lineNumber = 1;

var preOrder = "";
var inOrder = "";
var postOrder = "";

for (let i = 0; i < casesNumber; i++) {
    console.log(`Case ${i + 1}:`)

    let amountOfNumbers = parseInt(lines[lineNumber]);
    let listOfNumbers = lines[lineNumber + 1].trim().split(" ");

    let tree = {};
    for (let j = 0; j < amountOfNumbers; j++) {
        addNode(tree, parseInt(listOfNumbers[j]));
    }

    preOrder = "";
    inOrder = "";
    postOrder = "";

    printPreOrder(tree);
    printInOrder(tree);
    printPostOrder(tree);

    console.log(`Pre.: ${preOrder.trim()}`);
    console.log(`In..: ${inOrder.trim()}`);
    console.log(`Post: ${postOrder.trim()}`);
    console.log("");

    lineNumber += 2;
}

function printPostOrder(tree) {
    if (tree != undefined) {
        printPostOrder(tree.L);
        printPostOrder(tree.D);
        postOrder += tree.R + " ";

    }
}

function printInOrder(tree) {
    if (tree != undefined) {
        printInOrder(tree.L);
        inOrder += tree.R + " ";
        printInOrder(tree.D);
    }
}

function printPreOrder(tree) {
    if (tree != undefined) {
        preOrder += tree.R + " ";
        printPreOrder(tree.L);
        printPreOrder(tree.D);
    }
}

function addNode(tree, element) {
    if (tree.R == undefined) {
        tree.R = element;
    }
    else {
        if (element < tree.R) {
            if (tree.L == undefined) {
                tree.L = {};
            }
            addNode(tree.L, element);
        }
        else {
            if (tree.D == undefined) {
                tree.D = {};
            }
            addNode(tree.D, element);
        }
    }
}



