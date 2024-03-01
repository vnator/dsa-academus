import { expect, test  } from 'vitest'
import { binarySearch } from './binary-search'

test('Recursions - Binary Search', () => {
    const result = binarySearch([0,2,3,4,5,7,9,12,23,33,42,45], 23)

    expect(result).toBe(8)
})