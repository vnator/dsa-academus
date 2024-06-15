import { expect, test } from "vitest"
import { checkBrackets, count, reverse } from "./reverse"

test('reverse a list', () => {
    const result = reverse([1,2,3])
    expect(result).toEqual([3,2,1])
})

test('reverse a list', () => {
    const result = reverse([])
    expect(result).toEqual([])
})


test('convert to dict', () => {
    const result = count(["aa", "b", "c", "aa"])
    expect(result).toEqual({aa: 2, b: 1, c: 1})
})

test('check brackets 1', () => {
    const result = checkBrackets("[()]{}{[()()]()")
    expect(result).toBeTruthy()
})


test('check brackets 2', () => {
    const result = checkBrackets("[(])")
    expect(result).toBeFalsy()
})