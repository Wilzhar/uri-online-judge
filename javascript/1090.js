var input = require('fs').readFileSync('1090.txt', 'utf8');
var lines = input.split('\n');

for (let i = 0; i < lines.length; i++) {
    const line = lines[i].trim();

    if (line === '0') {
        break
    }

    if (!isNaN(line)) {
        var cards = lines.splice(i + 1, parseInt(line));

        console.log(findMaxCardCombination(cards));
    }
}

function findMaxCardCombination(cards) {

    var maxCardCombination = 0;

    var counts = {};

    cards.forEach(function (x) { counts[x.trim().replace(/\s/g, "_")] = (counts[x.trim().replace(/\s/g, "_")] || 0) + 1; });

    var countsMatrix = [[counts.um_circulo || 0, counts.dois_circulos || 0, counts.tres_circulos || 0],
    [counts.um_triangulo || 0, counts.dois_triangulos || 0, counts.tres_triangulos || 0],
    [counts.um_quadrado || 0, counts.dois_quadrados || 0, counts.tres_quadrados || 0]]


    // Calculating rows and cols
    for (let i = 0; i < countsMatrix.length; i++) {
        // Calculating by rows
        var row = [...countsMatrix[i]];

        const rowSmallest = Math.min(...row);

        countsMatrix[i][0] = row[0] - rowSmallest;
        countsMatrix[i][1] = row[1] - rowSmallest;
        countsMatrix[i][2] = row[2] - rowSmallest;

        // Calculating by cols
        var col = countsMatrix.map(function (value, index) { return value[i]; });

        const colSmallest = Math.min(...col);

        countsMatrix[0][i] = col[0] - colSmallest;
        countsMatrix[1][i] = col[1] - colSmallest;
        countsMatrix[2][i] = col[2] - colSmallest;

        // Incresing max combination number
        maxCardCombination = maxCardCombination + rowSmallest + colSmallest
    }

    // Calculating diagonal 1
    const diagonal1Smallest = Math.min(...[countsMatrix[0][0], countsMatrix[1][1], countsMatrix[2][2]]);

    countsMatrix[0][0] = countsMatrix[0][0] - diagonal1Smallest;
    countsMatrix[1][1] = countsMatrix[1][1] - diagonal1Smallest;
    countsMatrix[2][2] = countsMatrix[2][2] - diagonal1Smallest;

    // Calculating diagonal 2
    const diagonal2Smallest = Math.min(...[countsMatrix[0][2], countsMatrix[1][1], countsMatrix[2][0]]);

    countsMatrix[0][2] = countsMatrix[0][2] - diagonal2Smallest;
    countsMatrix[1][1] = countsMatrix[1][1] - diagonal2Smallest;
    countsMatrix[2][0] = countsMatrix[2][0] - diagonal2Smallest;

    // Calculating diagonal 3
    const diagonal3Smallest = Math.min(...[countsMatrix[0][0], countsMatrix[1][2], countsMatrix[2][1]]);

    countsMatrix[0][0] = countsMatrix[0][0] - diagonal3Smallest;
    countsMatrix[1][2] = countsMatrix[1][2] - diagonal3Smallest;
    countsMatrix[2][1] = countsMatrix[2][1] - diagonal3Smallest;

    // Calculating diagonal 4
    const diagonal4Smallest = Math.min(...[countsMatrix[2][2], countsMatrix[0][1], countsMatrix[1][0]]);

    countsMatrix[2][2] = countsMatrix[2][2] - diagonal4Smallest;
    countsMatrix[0][1] = countsMatrix[0][1] - diagonal4Smallest;
    countsMatrix[1][0] = countsMatrix[1][0] - diagonal4Smallest;

    // Calculating diagonal 5
    const diagonal5Smallest = Math.min(...[countsMatrix[2][0], countsMatrix[0][1], countsMatrix[1][2]]);

    countsMatrix[2][0] = countsMatrix[2][0] - diagonal5Smallest;
    countsMatrix[0][1] = countsMatrix[0][1] - diagonal5Smallest;
    countsMatrix[1][2] = countsMatrix[1][2] - diagonal5Smallest;

    // Calculating diagonal 6
    const diagonal6Smallest = Math.min(...[countsMatrix[0][2], countsMatrix[1][0], countsMatrix[2][1]]);

    countsMatrix[0][2] = countsMatrix[0][2] - diagonal6Smallest;
    countsMatrix[1][0] = countsMatrix[1][0] - diagonal6Smallest;
    countsMatrix[2][1] = countsMatrix[2][1] - diagonal6Smallest;

    maxCardCombination = maxCardCombination + diagonal1Smallest + diagonal2Smallest + diagonal3Smallest + diagonal4Smallest + diagonal5Smallest + diagonal6Smallest

    for (let i = 0; i < countsMatrix.length; i++) {

        for (let j = 0; j < countsMatrix[i].length; j++) {
            const cards = countsMatrix[i][j];

            if (cards >= 3) {
                maxCardCombination = maxCardCombination + (parseInt(cards / 3))

                countsMatrix[i][j] = cards % 3;
            }
        }
    }

    let matrixItems = [{ I: 0, j: 0 }, { I: 0, j: 0 }, { I: 0, j: 0 }];
    let pos = 0;
    let flag = true;

    // while (flag) {
    //     for (let i = 0; i < countsMatrix.length; i++) {
    //         for (let j = 0; j < countsMatrix[0].length; j++) {
    //             if (pos >= 3) {
    //                 for (let k = 0; k < matrixItems.length; k++) {
    //                     countsMatrix[matrixItems[k].I][matrixItems[k].J] -= 1;
    //                 }
    //                 maxCardCombination++;
    //                 pos = 0;
    //             }
    //             if (countsMatrix[i][j] != 0) {
    //                 matrixItems[pos].I = i;
    //                 matrixItems[pos].J = j;
    //                 pos++;
    //             }
    //         }
    //     }

    //     if (pos < 3) {
    //         flag = false;
    //     }
    // }




    return maxCardCombination
}