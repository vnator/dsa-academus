import readline from 'readline/promises';
import process from 'process';

async function main() {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  let list = (await rl.question("Digite a lista de numeros separadas por espaco e pressione Enter quando terminar: "))
    .split(" ")
    .map(n => Number(n));
  
  for (let i = list.length -1; i >= 0; i--) {
    console.log(`${list[i]} `);
  }

  rl.close();
}

main();

