import { expect, test } from  'vitest'
import { bubbleSortNonDecress } from './bubble-sort'

test('Bubble Sort Test', () => {
    expect(bubbleSortNonDecress([23, 4, 67, -8, 21])).toStrictEqual([-8, 4, 21, 23, 67])
})