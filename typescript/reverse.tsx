export function reverse(arr: number[]): number[] {
    const a: number[] = []
    for (let i = 0; i < arr.length; i++) {
        a.unshift(arr[i])
    }
    return a;
}

export function count(arr: string[]): Record<string, number> {
    return arr.reduce(
        (curr, next) => {
            if (curr[next]) {
                curr[next] = curr[next]+1
            } else {
                curr[next] = 1
            }

            return curr;
        }
    , {})
}

export function checkBrackets(str: string): boolean {
    
}