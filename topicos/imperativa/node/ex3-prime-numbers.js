import readline from 'readline/promises';
import { stdin, stdout } from  'process';

async function main() {

  const rl = readline.createInterface({
    input: stdin,
    output: stdout,
  })

  const list = (await rl.question("Entre com uma lista de numeros positivos inteiros: "))
                      .split(' ')
                      .map(item => Number(item))

  for (let item of list) {
    let itemIsPrimeNumber = isPrimeNumber(item);

    console.log(`${item}: ${itemIsPrimeNumber ? 'eh numero primo' : 'nao eh numero primo'}`);
  }

  rl.close();
}


function isPrimeNumber(n) {
  const primeNumberList = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37];

  if (n == 2) return true;
  if (n < 2) return false;
  if (n%2 == 0) return false;

  for (let p of primeNumberList) {
    if (n == p) return true;
    if (n%p == 0) return false;
  }

  let d = n-1;
  let s = 0;

  while (d%2 == 0) {
    d = d/2;
    s++;
  }

  for (let a of primeNumberList) {
    if (a >= n) break;

    let x = exponentialMod(a, d, n);

    if (x == 1 || x == n-1) continue;

    let finishLoop = false;


    for (let i = 1; i < s; i++) {
      x = (x*x) % n

      if (x == n-1) {
        finishLoop = true;
        break;
      }
    }

    if (!finishLoop) return false;
  }

  return true;
}

function exponentialMod (base, potency, divisor) {
  let result  = 1;

  let b = base%divisor;

  while(potency > 0) {
    if (potency%2 == 1) result = (result * b) % divisor;

    potency = Math.floor(potency / 2);

    b = (b*b) % divisor;
  }

  return result;
}

main();

