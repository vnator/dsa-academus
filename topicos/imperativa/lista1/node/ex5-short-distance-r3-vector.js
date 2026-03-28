import readline from 'readline/promises'
import process from 'process'

async function main() {
  const { stdin: input, stdout: output } = process

  const rl = readline.createInterface({
    input,
    output
  })

  const n = Number(await rl.question("Quantos vetores vo ira digitar? "))
  const vectorList = []

  let shortDistance;
  let vectorsElected = []

  for (let i = 0; i < n; i++) {
    vectorList.push(
      (await rl.question(`vetor ${i+1}, ex (1 2 1): `))
      .split(" ")
      .reduce((acc, cur, index) => {
        if (index == 1) return { x: Number(acc), y: Number(cur) }
        else return { ...acc, z: Number(cur) }
      })
    )
  }

  for (let i = 0; i < n-1; i++) {
    for (let j = i+1; j < n; j++) {
      let distance = distanceR3Vectors(vectorList[i], vectorList[j])

      if (
        (i == 0 && j == 1) ||
        distance < shortDistance
      ) {
        shortDistance = distance
        vectorsElected = [vectorList[i], vectorList[j]]
      }
    }
  }

  console.log(`Menor distancia enter vetores 
      A = (${vectorsElected[0].x}, ${vectorsElected[0].y}, ${vectorsElected[0].z})
    e B = (${vectorsElected[1].x}, ${vectorsElected[1].y}, ${vectorsElected[1].z})
    eh: ${shortDistance}`)
}

const distanceR3Vectors = (a, b) =>
  Math.sqrt(
    Math.pow(b.x - a.x, 2) +
    Math.pow(b.y - a.y, 2) +
    Math.pow(b.z - a.z, 2)
  )

main()
