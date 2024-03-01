import { expect, test } from 'vitest'
import { length } from './length'

test('Length function default test', () => {
    let result = length([0,0,0,0,0])
    expect(result).toBe(5)
})