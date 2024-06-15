//  r = removeEventListener
//  h = esquerda
//  l = direita
//  0..n = repetições

// SE FEZ COM REGEX É ROUBO

export function replaceStr(str: string, commands: string): { str: string; cursor: number } {
    let cursor = 0,
        i = 0,
        arr = str.split(""),
        times = 1; 

    while(i < commands.length) {
        let command = commands[i]

        if (command == 'l' && cursor < arr.length) {
            cursor += times
            times = 1
        } else if (command == 'h' && cursor > 1) {
            cursor -= times
            times = 1
        } else if (command == 'r') {

            for (
                let j = cursor;
                j < cursor+times && cursor < arr.length;
                j++
            ) { arr[j] = commands[i+1] }

            times = 1
        } else if (!isNaN(Number(command))) {
            let oldCommand = commands[i-1]
            if (
                !isNaN(Number(oldCommand))
            ) times = Number(times + command)

            times = Number(command)
        }

        // incrementa a posição do comando executado
        i++
    }

    return {
        str: arr.join(""),
        cursor
    }
} 