import { expect, test } from  'vitest'
import { insertionSortNonDecress } from './insertion-sort'

test('Insertion Sort Test', () => {
    expect(insertionSortNonDecress([23, 4, 67, -8, 21])).toStrictEqual([-8, 4, 21, 23, 67])
})