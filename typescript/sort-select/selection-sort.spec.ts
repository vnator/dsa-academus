import { expect, test } from  'vitest'
import { selectionSortNonDecress } from './selection-sort'

test('Selection Sort Test', () => {
    expect(selectionSortNonDecress([23, 4, 67, -8, 21])).toStrictEqual([-8, 4, 21, 23, 67])
})