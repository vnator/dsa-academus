export function euclidesCalc(width: number, height: number): number {
  const [less, higher] = width > height ? [height, width] : [width, height];

  if (higher % less == 0) return less;

  const rest = higher - less * Math.floor(higher / less);

  return euclidesCalc(rest, less);
}
