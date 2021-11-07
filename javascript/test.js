const fs = require('fs');

var msg = "";

for (let j = 0; j < 2000; j++) {
    // let max = 1000;
    // let min = 9;
    // var numLines = Math.floor(Math.random() * (max - min) + min);
    var numLines = 5;
    msg += `${numLines}\n`;
    for (let i = 0; i < numLines; i++) {
        let randomNum = Math.floor(Math.random() * 10);

        switch (randomNum) {
            case 0:
                msg += "um circulo\n";

                break;
            case 1:
                msg += "dois circulos\n";
                break;
            case 2:
                msg += "tres circulos\n";
                break;
            case 3:
                msg += "um triangulo\n";
                break;
            case 4:
                msg += "um triangulo\n";
                break;
            case 5:
                msg += "dois triangulos\n";
                break;
            case 6:
                msg += "tres triangulos\n";
                break;
            case 7:
                msg += "um quadrado\n";
                break;
            case 8:
                msg += "dois quadrados\n";
                break;
            case 9:
                msg += "tres quadrados\n";
                break;

        }
    }
}


msg += "0";


fs.writeFile("./test.txt", msg, function (err) {
    if (err) {
        return console.log(err);
    }
    console.log("The file was saved!");
});
