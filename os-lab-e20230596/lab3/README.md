# Lab 3 — Wildcards, Hard Links and Symbolic Links: individual report

- Student name/ID: CHHEM SOPHEA, e20230596
- Ubuntu username: gic-chhem-sophea
- My values (`oslab values lab3`): name = river, tag = draft, v1 = 286, v2 = 339
- Files: `evidence/wildcards.txt`, `evidence/links.txt`, `evidence/replacement.txt`, `evidence/checkpoint.txt`

## What I Saw

| State | What `cat` printed for the hard link | What `cat` printed for the symbolic link | What `readlink` printed |
|---|---|---|---|
| Before the rename | version 286 | version 286 | river.txt |
| After the rename, before the repair | version 286 | No such file or directory | river.txt |
| After a new file took the old name | version 286 | version 339 | river.txt |
| After my repair | version 286 | version 286 | river-draft.txt |

My repair (the two commands I wrote):

```bash
rm -- river-soft.txt
ln -s river-draft.txt river-soft.txt
```

## Explanation

The hard link `river-hard.txt` points to inode 19017411, the same inode as my original report, now named `river-draft.txt`, so it always reads version 286. The symbolic link only stores the name `river.txt`. After the rename no file had that name, so it was dangling. When a new `river.txt` was created, it got a new inode (19017226) holding version 339, and the symbolic link followed the name to that new file. The surprise was the symbolic link: it worked again but read the wrong file.

## What My Tests Do Not Prove

`cat` only shows the content, so two different files with the same text would look the same. Only `ls -li` (same inode number) proves that two names are really the same file.

## Plus / Challenge (only if you did them)

- Plus: `river[12].txt` gave river1.txt and river2.txt; `river[!1]*` gave river2.txt and river.log (I did not expect river.log, but "." is not "1").
- Challenge: link counts went 3 → 2 → 1. The data stays while at least one name points to the inode.

## AI Note (optional)

None
