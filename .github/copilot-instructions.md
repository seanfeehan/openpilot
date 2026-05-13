# Copilot Instructions for codemap

Use the `codemap` MCP tools as the first source of truth for understanding this repository before reading large files or making non-trivial changes.

## Operating rules

- Prefer `codemap-context` first for any feature, bug fix, refactor, or architecture question.
- Before changing an existing symbol, run `codemap-impact` to identify direct and indirect callers.
- When a task mentions behavior but not exact code locations, use `codemap-search` to find candidate symbols, then inspect with `codemap-node` or `codemap-definition`.
- When tracing execution flow, use `codemap-path`, `codemap-callers`, and `codemap-callees` instead of broad file reads.
- When working in a specific file, use `codemap-file` to enumerate symbols before editing.
- Use `codemap-references` to find usages across the codebase before renaming, deleting, or changing signatures.
- Use `codemap-implementations` when the task refers to an interface, trait, base class, or abstraction.
- Use `codemap-unused` before removing code that appears dead.
- Keep file reads targeted. Do not read whole directories when codemap can narrow the scope.
- If codemap results and source files disagree, trust the source files and note that the index may need refresh.
- If a symbol is missing or stale, ask to re-run `codemap index` or note that the index may not reflect the latest edits.

## Default workflow

For non-trivial requests, follow this sequence:

1. Clarify the task in one sentence.
2. Run `codemap-context` with the task phrased as an engineering objective.
3. Identify the likely entry points, affected symbols, and related files from codemap output.
4. Run `codemap-impact` on symbols that will be modified.
5. Read only the specific definitions or files needed to make the change.
6. Make the minimal correct edit.
7. Summarize what changed, why, and what callers or flows were considered.

## Prompt patterns

### Understand a feature
Use `codemap-context` for: "Explain how authentication works in this repository, including entry points, key functions, and downstream dependencies."

### Safe refactor
Use `codemap-impact` on the target symbol, then inspect callers and references before changing the signature or behavior.

### Find the right edit point
Use `codemap-search` for likely symbol names, then `codemap-definition` on the best matches.

### Trace a flow
Use `codemap-path` to answer questions like: "How does `main` reach the database layer?"

### Cleanup
Use `codemap-unused` and then confirm with `codemap-references` before deleting code.

## Editing constraints

- Do not rename public APIs, exported symbols, or shared interfaces without checking references and impact first.
- Do not change behavior across multiple call sites without identifying the blast radius.
- Prefer small, reviewable patches.
- Preserve existing project conventions unless the task explicitly requests a broader refactor.

## When codemap should be refreshed

Assume the codemap index needs refresh when:

- recently added files or symbols are not found;
- call relationships appear incomplete;
- references do not match current source;
- large refactors were done outside the current session.

Suggested command:

```bash
codemap index
```

## MCP expectations

This workspace may expose codemap through MCP in VS Code. If the tools are available, use them proactively for code understanding. If they are unavailable, say so briefly and fall back to targeted file inspection.