import { expect, test } from "vitest"
import { replaceStr } from "./dsa"


// mover 
test('Print Result A', () => {
    const result = replaceStr("Hello Grupo Boticario", "hhllllhlhhl")
    expect(result).toEqual({
        str: "Hello Grupo Boticario",
        cursor: 3
    })
})


// mover e substituir
test('Print Result B', () => {
    const result = replaceStr("Hello Grupo Boticario", "rhllllllrgllllllrb")
    expect(result).toEqual({
        str: "hello grupo boticario",
        cursor: 12
    })
})

test('Print Result C', () => {
        const result = replaceStr("Hello Grupo Boticario", "rh6lrg6666lrb2h")
    expect(result).toEqual({
        str: "hello grupo boticario",
        cursor: 10
    })
})


test('Print Result B', () => {
    const result = replaceStr("Hello Grupo Boticario", "9999lrO")
    expect(result).toEqual({
        str: "Hello Grupo BoticariO",
        cursor: 20
    })
})

test('Print Result C', () => {
        const result = replaceStr("Hello Grupo Boticario", "21rA")
    expect(result).toEqual({
        str: "AAAAAAAAAAAAAAAAAAAAA",
        cursor: 20
    })
})