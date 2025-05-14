#!/usr/bin/env bash
# ------------------------------------------------------------------
# Build a local folder hierarchy from the “LeetCode_FAANG_200_Template.csv”
#   Pattern/          ← e.g. arrays_hashing/
#     Problem/        ← e.g. two_sum/
#       README.md     ← prompt-ready template (intuition + complexity)
#       solution.cpp  ← blank C++ stub
#
#   Usage:  ./generate_leetcode_structure.sh  <csv>  [root_dir]  [file_name]
#           csv       – path to the template CSV (default same dir)
#           root_dir  – where to create folders      (default ./leetcode)
#           file_name – single file per problem      (default solution.cpp)
# ------------------------------------------------------------------

set -euo pipefail

CSV_FILE=${1:-LeetCode_FAANG_200_Template.csv}
ROOT_DIR=${2:-leetcode}
PROBLEM_FILE=${3:-solution.cpp}

# Convert a string to a filesystem-safe slug: lower-case, keep a-z0-9, change others to _
slug() {
  printf '%s' "$1" \
  | tr '[:upper:]' '[:lower:]' \
  | sed -E 's/[[:space:]]+/_/g; s/[^a-z0-9_]/_/g; s/_+/_/g; s/^_//; s/_$//'
}

echo "• Reading: $CSV_FILE"
echo "• Root   : $ROOT_DIR"
echo "• File   : $PROBLEM_FILE"
echo

# mkdir -p "$ROOT_DIR"

# Skip header, then read first three columns: Pattern, Problem, Link
tail -n +2 "$CSV_FILE" \
| while IFS=',' read -r pattern problem link _; do
    # Trim surrounding quotes (if the CSV exporter added them)
    pattern=${pattern%\"};  pattern=${pattern#\"}
    problem=${problem%\"};  problem=${problem#\"}
    link=${link%\"};        link=${link#\"}

    pattern_dir=$(slug "$pattern")
    problem_dir=$(slug "$problem")

    full_dir="$pattern_dir/$problem_dir"
    mkdir -p "$full_dir"

    # 1️⃣ Markdown skeleton (only create if missing so you can edit later)
    readme="$full_dir/README.md"
    if [[ ! -e "$readme" ]]; then
        cat >"$readme" <<EOF
# $problem

> **Pattern:** $pattern  
> [LeetCode problem]($link)

## Intuition

| Approach | Idea |
|----------|------|
| Brute-force | |
| Better | |
| Optimal | |

## Complexity

| Approach  | Time | Space |
|-----------|------|-------|
| Brute-force |  |  |
| Better |  |  |
| Optimal |  |  |

EOF
    fi

    # 2️⃣ Blank code stub (language-agnostic; default C++)
    touch "$full_dir/$PROBLEM_FILE"

    echo "✓ $pattern ➜ $problem"
done

echo
echo "All folders & files generated under '$pattern'. Happy grinding!"
