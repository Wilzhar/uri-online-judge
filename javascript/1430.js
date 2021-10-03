var input = require('fs').readFileSync('1430.txt', 'utf8');
var lines = input.split('\n');

var notes = {
    W: 1,
    H: 2,
    Q: 4,
    E: 8,
    S: 16,
    T: 32,
    X: 64
};



for (let i = 0; lines[i] !== "*"; i++) {
    let rightMeasures = 0;
    let measures = lines[i].split("/");
    for (let j = 1; j < measures.length - 1; j++) {
        let measureDuration = 0;
        let measure = measures[j];

        for (let k = 0; k < measure.length; k++) {
            let note = measure[k];
            measureDuration += 1 / notes[note];

        }

        if (measureDuration == 1) {
            rightMeasures++;
        }
    }
    console.log(rightMeasures)
}

