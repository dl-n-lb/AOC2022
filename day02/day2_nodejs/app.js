const fs = require('fs');

const luta = {
  'A X' : 4,
  'A Y' : 8,
  'A Z' : 3,
  'B X' : 1,
  'B Y' : 5,
  'B Z' : 9,
  'C X' : 7,
  'C Y' : 2,
  'C Z' : 6,
  '' : 0
}

const lutb = {
  'A X' : 3,
  'A Y' : 4,
  'A Z' : 8,
  'B X' : 1,
  'B Y' : 5,
  'B Z' : 9,
  'C X' : 2,
  'C Y' : 6,
  'C Z' : 7,
  '' : 0
}

async function partA() {
  const data = fs.readFileSync('../input.txt', {encoding: 'utf8'});
  const lines = data.split('\n');
  var total = 0;
  for (line of lines) {
    total += luta[line];
  }
  console.log(total);
}

async function partB() {
  const data = fs.readFileSync('../input.txt', {encoding: 'utf8'});
  const lines = data.split('\n');
  var total = 0;
  for (line of lines) {
    total += lutb[line];
  }
  console.log(total);
}

try {
  partA();
  partB();
}
catch(e) {
  console.log(e);
}