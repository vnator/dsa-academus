import { describe, expect, test } from "vitest";
import { euclidesCalc } from "./euclides-calc";

describe("Recur sion - Euclides Calc", () => {
  test("Function euclidesCalc", () => {
    const result = euclidesCalc(1680, 640, 1);

    expect(result).toBe(80);
  });

  test("Function euclidesCalc", () => {
    const result = euclidesCalc(640, 640, 1);

    expect(result).toBe(640);
  });
});
