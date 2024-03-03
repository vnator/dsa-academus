import { describe, expect, test } from "vitest";
import { quickSort } from "./quick-sort";

describe("Sort Select - quick sort algorithm", () => {

    test("Function quickSort", () => {
        const result = quickSort([32,54,1,5,6,8,122,44,35,66])

        expect(result).toStrictEqual([
            1,  5,  6,  8,  32,
           35, 44, 54, 66, 122
         ])
    })
    
    
    test("Function quickSortPartition", () => {
        const result = quickSort([32,54,1,5,6,8,122,44,35,66])

        expect(result).toStrictEqual([
            1,  5,  6,  8,  32,
           35, 44, 54, 66, 122
         ])
    })
})
