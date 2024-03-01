import { expect, test } from  'vitest'
import { some } from './some'

test('Test Sum default usage', () => {
	let result = some([2,32,10,6,10,20])

	expect(result).toBe(80)
})
