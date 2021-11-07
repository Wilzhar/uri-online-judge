const { time } = require('console');

var input = require('fs').readFileSync('1523.txt', 'utf8');
var lines = input.split('\n');

var carsAndParkingLot = lines[0].trim().split(" ");
var carsNumber = parseInt(carsAndParkingLot[0]);
var parkingLotSlots = parseInt(carsAndParkingLot[1]);
var start = 1;
var finish = carsNumber + 1;

while (carsNumber) {

    if (carsNumber == 0) {
        break;
    }

    let times = [];

    for (let i = start; i < finish; i++) {
        let carTimes = lines[i].trim().split(" ");
        let arriveTime = parseInt(carTimes[0]);
        let exitTime = parseInt(carTimes[1]);

        // console.log("arriveTime", arriveTime, "exitTime", exitTime)

        let currentTime = times.find(time => time == arriveTime);

        if (!currentTime) {
            times.push(arriveTime);
        }

        currentTime = times.find(time => time == exitTime);

        if (!currentTime) {
            times.push(exitTime);
        }
    }

    let queue = [];

    let flag = true;

    times.sort((a, b) => { return a - b; })


    for (let j = 0; j < times.length && flag; j++) {
        let time = times[j];
        for (let i = start; i < finish && flag; i++) {
            let leaved = false;
            let carTimes = lines[i].trim().split(" ");
            let arriveTime = parseInt(carTimes[0]);
            let exitTime = parseInt(carTimes[1]);

            let carPos = finish - (finish - i);

            // console.log("arriveTime", arriveTime, "exitTime", exitTime)

            if (arriveTime == exitTime) {
                if (!(arriveTime == exitTime || queue.length < parkingLotSlots)) {
                    flag = false;
                    // console.log("nao 0")
                    console.log("Nao");
                    leaved = true;
                }
            }
            else {
                if (arriveTime == time) {
                    if (exitTime == time) {
                        if (carPos == queue[queue.length - 1]) {
                            queue.pop(carPos);
                            leaved = true;

                            // console.log("leaving", carPos)
                            // console.log(queue)
                        }
                        else {
                            flag = false;
                            // console.log("nao 1")
                            console.log("Nao");
                            leaved = true;
                        }
                    }
                    if (queue.length < parkingLotSlots) {
                        // console.log("pushing", carPos)
                        queue.push(carPos);
                        leaved = true;
                        // console.log(queue)
                    }
                    else {
                        // console.log("there is not available slots :(")
                        flag = false;
                        // console.log("nao 2")
                        console.log("Nao");
                        leaved = true;
                    }
                }

                if (!leaved) {
                    if (exitTime == time) {
                        if (carPos == queue[queue.length - 1]) {
                            queue.pop(carPos);
                            // console.log("leaving", carPos)
                            // console.log(queue)
                        }
                        else {
                            flag = false;
                            // console.log("nao 3")
                            console.log("Nao");
                        }
                    }
                }
            }
        }
    }

    if (flag) {
        console.log("Sim")
    }

    carsAndParkingLot = lines[finish].trim().split(" ");
    carsNumber = parseInt(carsAndParkingLot[0]);
    parkingLotSlots = parseInt(carsAndParkingLot[1]);

    start = finish + 1;
    finish = parseInt(start + carsNumber);
}