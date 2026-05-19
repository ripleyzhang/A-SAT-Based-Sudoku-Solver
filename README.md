# SAT_DPLL_SuKoDu

## Project Description

**SAT_DPLL_SuKoDu** is a project that converts Sudoku-style puzzle problems into SAT problems and solves SAT instances based on the **DPLL algorithm framework**.

After entering the main interactive interface, the user will see two options:

1. **SAT**
2. **BinaryPuzzle**

---

## 1. SAT Mode

In **SAT Mode**, the user should first load a **CNF file** before performing other operations such as saving, traversing, or running the DPLL solver.

The correct workflow is:

```text
Load CNF file → Save / Traverse / Run DPLL
```

If the operations are performed in the wrong order, an error will occur.

When running DPLL, there are two available options:

```text
1. Original version
2. Optimized version
```

Only one of the two versions can be selected at a time.

After the DPLL algorithm finishes, the loaded file will be destroyed. Therefore, if the user wants to perform another operation on the same file, the CNF file must be loaded again.

---

## 2. BinaryPuzzle Mode

In **BinaryPuzzle Mode**, the user should first load a puzzle board file. The board files have already been included in the compressed project package.

After loading the board file, the user can either:

```text
1. Choose PLAY
2. Directly choose setCNFfile
```

### Option 1: Directly Choose `setCNFfile`

If the user directly chooses `setCNFfile`, the puzzle will be converted into a CNF file.

After that, the user can run the DPLL solver to obtain the solution. The result will be displayed on the screen.

The workflow is:

```text
Load board file → setCNFfile → Run DPLL → Display result
```

### Option 2: Choose `PLAY` First

If the user chooses `PLAY` first and then chooses `setCNFfile`, there will be two options:

```text
1. Solve directly
2. Verify whether the board filled by the user is correct
```

#### Option 1: Solve Directly

The program will initialize the board and solve the puzzle directly.

The workflow is:

```text
Load board file → PLAY → Solve directly → setCNFfile → Run DPLL
```

#### Option 2: Verify User Input

If the board has not been completely filled, the program will prompt the user to complete the board before continuing.

If the board has been completely filled, the user can continue with the following operations:

```text
setCNFfile → Run DPLL
```

After DPLL finishes, the program will display a message indicating whether the user’s solution is correct or incorrect.

---

## Notes

* In **SAT Mode**, a CNF file must be loaded before performing any SAT-related operations.
* In **SAT Mode**, the file will be destroyed after running DPLL, so the CNF file must be reloaded for further operations.
* In **BinaryPuzzle Mode**, the board file must be loaded before playing or converting the puzzle into CNF.
* The DPLL solver provides both an original version and an optimized version, but only one can be selected for each run.
