# 🧮 Meeting Point on a Circle – Beginner-Friendly Mathematical Explanation

## 📘 Problem Description

You and your friend are playing a game on a circle with **100** points, equally spaced and numbered `1` through `100`. 

### Movement Rules:
- You both start at **point 1**.
- You move **1 step** at a time in a clockwise direction.
- Your friend moves **k steps** forward every time **you move once**.
- Movement wraps around (i.e., it's modular arithmetic on a circle of 100 points).

---

## 🎯 Objective

Determine:
1. Will you and your friend **meet again** after some time?
2. If yes, after how many of **your steps**?
3. At **which point** on the circle do you meet?

---

## 🧠 Step-by-Step Mathematical Modeling

Let:
- `n = 100` (number of points on the circle)
- `k` = number of steps your friend takes when you take 1 step
- `t` = number of your steps until you meet again

### ➕ Position Tracking

After `t` of your steps:
- Your position:  
  \[
  P(t) = (1 + t) \mod n
  \]

- Your friend's position:  
  \[
  F(t) = (1 + kt) \mod n
  \]

---

## 🟰 When Do You Meet?

You and your friend meet when:
\[
P(t) \equiv F(t) \mod n
\]

Substitute the expressions:
\[
1 + t \equiv 1 + kt \mod n
\]

Cancel 1 from both sides:
\[
t \equiv kt \mod n
\Rightarrow (k - 1)t \equiv 0 \mod n
\]

This is a **modular congruence** equation. It asks:

> For which smallest value of `t` is `(k - 1) * t` divisible by `n`?

---

## ✨ Key Result

The smallest value of `t` that satisfies:
\[
(k - 1)t \equiv 0 \mod n
\]
is:
\[
t = \frac{n}{\gcd(k - 1, n)}
\]

This ensures `(k - 1)t` is a multiple of `n`, so both positions match modulo `n`.

---

## ✅ Final Answer Format

- You will always meet again.
- You meet after:
  \[
  t = \frac{n}{\gcd(k - 1, n)}
  \]
- You meet at point:
  \[
  (1 + t) \mod n
  \]

---

## 🔢 Examples

### Example 1: Friend moves 3 steps each time (`k = 3`)
- \( k - 1 = 2 \)
- \( \gcd(2, 100) = 2 \)
- \( t = 100 / 2 = 50 \)
- Meeting point: \( (1 + 50) \mod 100 = 51 \)

✅ Meet at **point 51** after **50 steps**.

---

### Example 2: Friend moves 8 steps (`k = 8`)
- \( k - 1 = 7 \)
- \( \gcd(7, 100) = 1 \)
- \( t = 100 / 1 = 100 \)
- Meeting point: \( (1 + 100) \mod 100 = 1 \)

✅ Meet again at the **starting point** after **100 steps**.

---

### Example 3: Friend moves 9 steps (`k = 9`)
- \( k - 1 = 8 \)
- \( \gcd(8, 100) = 4 \)
- \( t = 100 / 4 = 25 \)
- Meeting point: \( (1 + 25) \mod 100 = 26 \)

✅ Meet at **point 26** after **25 steps**.

---

## 🧮 Conclusion

You and your friend **always** meet again, no matter how many steps `k` your friend takes, because:

- The equation \( (k - 1)t \equiv 0 \mod n \) always has a solution.
- You meet after \( t = \frac{n}{\gcd(k - 1, n)} \) of your steps.
- This relies on properties of **modular arithmetic** and the **greatest common divisor (GCD)**.

---

## 📘 Further Reading

- Modular Arithmetic: [Khan Academy](https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/modular-arithmetic)
- Linear Congruences: [Wikipedia](https://en.wikipedia.org/wiki/Modular_arithmetic#Congruence_relations)