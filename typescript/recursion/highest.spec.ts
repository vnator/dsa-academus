import { expect, test, describe } from "vitest";
import { highest } from "./highest";

describe('Highest number suite', () => {
    test('check if its more highest', () => {
        const result = highest([1,2,3,4,5,6,7])
        expect(result).toBe(7)
    })
    
    test('check if its more highest in the middle', () => {
        const result = highest([1,2,3,23,55,43,233,4,5,6,7])
        expect(result).toBe(233)
    })

    test('check if its more highest everythin 0', () => {
        const result = highest([0,0,0,0])
        expect(result).toBe(0)
    })
})