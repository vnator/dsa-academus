const readline = require('readline/promises');
const { stdin: input, stdout: output } = require("process");

async function readAndPrint() {
  const rl = readline.createInterface({
    input,
    output,
  });

  const strList = await rl.question(' Entre com uma lista separada por espaco e pressione ENTER quando: ');
  
  console.log(strList);

  const list = strList
      .split(" ")
      .map(i => Number(i))
      .filter(i => i%2 == 0);

  console.log(`${list.length} numeros pares foram inseridos;`);

  rl.close();
}

readAndPrint();


