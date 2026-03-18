const readline = require("readline/promises");
const { stdin: input, stdout: output } = require("process");

function findMinMaxCommonDivisor() {
  const rl = readline.createInterface({
    input,
    output,
  });

  const inputA = Number(await rl.question("Entre com o primeiro numero, deve ser valor maior que zero: "));
  const inputB = Number(await rl.question("Entre com o segundo numero, tambem deve ser maior que zero: "));
  const primeNumberList = [2];

  let min = -1;
  const max = findMaxCommonDivisor(inputA, inputB);

  if (max == 1) {
    console.log("minDivisorComum = maxDivisorComum = 1");
    rl.close();
  }

  while(true) {
    const lastPrime = primeNumberList[primeNumberList.length-1];

    if (inputA % lastPrime == 0 && inputB % lastPrime == 0) {
      min = lastPrime;
      break;
    }

    primeNumberList.push(
      findNextPrimeNumber(primeNumberList)
    );

    if (lastPrime > max) break;
  }

  console.log(
    `Minimo Divisor comum = ${min}, Maximo Divisor comum = ${max}`
  );


  rl.close();
}

function findNextPrimeNumber(primeNumberList) {
  let size = primeNumberList.length;
  let candidate = primeNumberList[size - 1];

  while(true) {
    let isPrime = true;
    candidate = candidate == 2 ? 3 : candidate + 2;

    for(const p of primeNumberList) {
      if (!(candidate % p)) {
        isPrime = false;
        break;
      }
    }

    if (isPrime) return candidate;
  }
}

function findMaxCommonDivisor(a, b) {
  if (!b) return a;

  const c = a % b;
 
  return findMaxCommonDivisor(b, c);
}

findMinMaxCommonDivisor();
