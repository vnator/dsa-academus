export function some(arr: number[], idx: number = 0):number {
	let result = arr[idx] ?? 0

	if (idx < arr.length) {
		idx++
		result+= some(arr, idx)
	}

	return result;
}