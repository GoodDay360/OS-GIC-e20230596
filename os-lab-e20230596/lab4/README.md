# Lab 4 — Redirection and Pipelines: individual report

- Name / student ID: CHHEM SOPHEA, e20230596
- Linux account: gic-chhem-sophea
- Personal status and other word: status = shipped, other = clear

## Commands I Used

All my commands are in `evidence/commands.txt` (one per line, not a script).

| Stage | My command | Input received | Output produced |
|---|---|---|---|
| Select exact first field | `grep '^shipped,' data/events.csv \| tee evidence/selected.txt` | the 7 lines of `events.csv` (header + 6 records) | 3 full rows: `shipped,4`, `shipped,6`, `shipped,9` (shown and saved) |
| Extract field 2 | `grep '^shipped,' data/events.csv \| cut -d, -f2 \| tee evidence/fields.txt` | the 3 rows from `grep` | only the numbers `4`, `6`, `9` |
| Count selected records | `grep '^shipped,' data/events.csv \| wc -l > evidence/normal.txt` | the 3 rows from `grep` | `3`, saved in the file (nothing on screen) |
| Save stdout and stderr separately | `cat data/missing.csv > evidence/stdout.txt 2> evidence/stderr.txt` | a file name that does not exist | `stdout.txt` empty, `stderr.txt` has `cat: data/missing.csv: No such file or directory` |
| Save exit status immediately | `echo $? > evidence/status.txt` | the status of the `cat` just before | `1` |

What changed between stages: first I only picked the rows with `grep` to check that `shipped-late,70` was not included. Then I added `cut` to keep only field 2. In the last stage I replaced `cut` with `wc -l`, because I wanted the number of rows, not the numbers inside them. `diff -u data/expected.txt evidence/normal.txt` printed nothing, so my count matches the expected one.

## What My Tests Show

| Test | Expected | Observed | Mistake it would catch |
|---|---|---|---|
| Original records | 3 exact matches | 3 (`shipped,4`, `shipped,6`, `shipped,9`), `shipped-late,70` not selected | Prefix matching: `grep '^shipped'` without the comma would also take `shipped-late` and give 4 |
| No match | 0 records | 0 | Assuming there is always a match; also shows `wc -l` gives 0 and not an error when `grep` finds nothing |
| One added match plus a look-alike | 4 records | 4 (second line of `edge.txt`) | Adding quantities instead of counting (`shipped,7` added 1, not 7), prefix matching (`shipped-late,99` did not count), and using `>` for the second line (it would erase the `0`, so `edge.txt` would only have `4`) |
| Missing input | empty stdout, diagnostic on stderr, nonzero status | `stdout.txt` empty, `stderr.txt` has the "No such file" message, `status.txt` = 1 | Thinking the error message is normal output, or checking `$?` too late |

`oslab check lab4` gave PASS for all four Core milestones (4/4).

## Explain the Commands

1. **Why does the comma in `grep '^WORD,'` matter?**
   `^shipped` only says "line starts with shipped", so `shipped-late,70` also matches. The comma marks the end of the first field, so the first field must be exactly `shipped`.

2. **Why does `wc -l` count records here, rather than add quantities?**
   `wc -l` only counts lines. Each selected line is one record, so it gives 3. It never looks at the numbers. If I wanted the total (4+6+9 = 19), that is a different question.

3. **Where did you use `>>`, and what would `>` do instead?**
   In the second line of the edge test: `grep '^shipped,' data/changed.csv | wc -l >> evidence/edge.txt`. `>>` adds the 4 under the 0. With `>` the file would be cleared first and only `4` would remain. I also saw this in the guided part: `practice.txt` kept "first observation" because the second line used `>>`.

4. **What does `tee` do that `>` alone does not?**
   `tee` shows the output on screen and saves it to the file at the same time. With `>` the output only goes to the file and I see nothing.

5. **Why must `echo $?` immediately follow the command being checked?**
   `$?` only keeps the status of the last command. If I ran `cat evidence/stdout.txt` first, `$?` would be 0 from that `cat`, not 1 from the missing file.

6. **Why can `cat missing-file | wc -l` report pipeline status 0?**
   A pipeline returns the status of its last command. `cat` fails (status 1) but `wc -l` still works fine and prints 0, so `$?` is 0. I tried it: the error message appeared, `wc` printed `0` and `echo $?` printed `0`. So a 0 here does not mean the file was read.

## Limits and Evidence

These commands assume simple comma-separated text without quoted commas. Saved results describe one run; they do not prove every future input works or who typed a command.

Submission files: `checkpoint.txt` and `evidence/commands.txt`, `selected.txt`, `fields.txt`, `normal.txt`, `edge.txt`, `stdout.txt` (empty on purpose), `stderr.txt`, `status.txt`, `checkpoint-selected.txt`. Screenshots of my terminal are in `screenshots/`.

## Optional Work / AI Note

- **Instructor demo:** `cat data/missing.csv | wc -l` showed the error, printed `0`, and `echo $?` gave `0`.
- **Plus:** `grep '^shipped,' data/no-match.csv` printed nothing and `echo $?` gave `1`. For `grep`, 1 means "no matching line", the file was read fine. The missing file is a different case: there `cat` printed an error on stderr. So "no match" is not the same as "file missing".
- **Challenge:** `cat data/events.csv data/missing.csv 2>&1 | tee evidence/challenge.txt`. First I tried it without `2>&1`: the error still showed on screen but `challenge.txt` only had the CSV lines. That is because `|` only sends stdout to `tee`; stderr goes straight to the terminal. `2>&1` must be before the `|` so stderr joins stdout and goes into the pipe. After that, the error line was in the file too.
- **AI note:** I used AI to help me practice and write up this report. Prediction and checkpoint were done by myself.
