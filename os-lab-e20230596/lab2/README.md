# Lab 2 — Linux Navigation and File Management: individual report

Copy this template to `lab2/README.md` in your own course repository. Follow [the instructions](lab2-instruction.md). Your prediction, debrief and checkpoint answers are already saved by `oslab`; do not copy them here. The marks come from those records and your evidence files; this report is your own record of the lab.

- Student name/ID: CHHEM SOPHEA
- Ubuntu username: gic-chhem-sophea
- My values (`oslab values lab2`): file1 = vendor list.txt, file2 = payroll may.txt, owner = Sales, reader = Marketing, third = HR
- Files: `evidence/paths.txt`, `evidence/tree.txt`, `evidence/checkpoint.txt`

## What I Did

| Step | My command | Current folder when I ran it |
|---|---|---|
| Move the first file (relative destination) | `mv "$file1" ../reports/` | `$OSLAB_WORKSPACE/lab2/incoming` |
| Move the second file (absolute paths) | `mv "$OSLAB_WORKSPACE/lab2/incoming/$file2" "$OSLAB_WORKSPACE/lab2/reports/$file2"` | `$OSLAB_WORKSPACE/lab2` |
| Read the report from my reader department (relative path) | `cat ../Sales/vendor list.txt` | `$OSLAB_WORKSPACE/lab2/TechCorp/Marketing` |
| The path error I made on purpose, and its message | `cat "reports/$file1"` → `cat: 'reports/vendor list.txt': No such file or directory` | `$OSLAB_WORKSPACE/lab2/TechCorp/Marketing` |
| The relative path that fixed it | `../../reports/vendor list.txt` | `$OSLAB_WORKSPACE/lab2/TechCorp/Marketing` |

## Explanation

`oslab debrief lab2` records which prediction answers you confirmed and which you corrected. Here, in 3–5 sentences for yourself: why can a correct file name still give "No such file or directory"? What is the difference between `mv` and `cp`, using your own files as the example?

A relative path is always based on the current folder. From `TechCorp/Marketing`, the path `reports/vendor list.txt` looks for a `reports` folder inside `Marketing`, which does not exist. The correct path depends on where the file actually is: if I want the file in `TechCorp/Sales`, I need to go to the parent folder first; if I want the report in `reports/`, I must go up two levels before entering `reports`. This is why a file name can be correct but still fail when the path is interpreted from the wrong folder.


## What My Tests Do Not Prove

One or two sentences. Think about what `ls` shows and what `cmp` shows.


`ls` only shows the names of files and folders, not whether the contents are the same. `cmp` checks every byte in both files and prints nothing only when they are identical, so it proves content equality, not meaning or correctness of the file itself.


## Plus / Challenge (only if you did them)

Your one-command move and the number of `..`, or your wildcard answers.

## AI Note (optional)

One suggestion an AI tool gave you and the test you used to check it.
