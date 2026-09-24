# Problem 3: Time Conversion

## Overview
Given a time string `s` in 12-hour AM/PM format (`hh:mm:ssAM` or `hh:mm:ssPM`), convert it to 24-hour military time (`HH:mm:ss`), where:
- $00 \le hh \le 12$
- $00 \le mm, ss \le 59$
- $12:00:00\text{AM}$ maps to $00:00:00$
- $12:00:00\text{PM}$ maps to $12:00:00$

## Conversion Logic Matrix
| Input Period | Hour Condition | Operation | Example Input | Output |
| :--- | :--- | :--- | :--- | :--- |
| **AM** | `hh == 12` | `hh = 00` | `12:05:45AM` | `00:05:45` |
| **AM** | `hh < 12` | Keep `hh` as is | `07:15:30AM` | `07:15:30` |
| **PM** | `hh == 12` | Keep `hh` as 12 | `12:40:22PM` | `12:40:22` |
| **PM** | `hh < 12` | `hh = hh + 12` | `07:05:45PM` | `19:05:45` |

## Complexity Analysis
- **Time Complexity:** $\mathcal{O}(1)$  
  Parsing and formatting a fixed 10-character string takes bounded constant time.
- **Space Complexity:** $\mathcal{O}(1)$  
  Allocates a static 9-byte buffer (`HH:MM:SS\0`) for output.
