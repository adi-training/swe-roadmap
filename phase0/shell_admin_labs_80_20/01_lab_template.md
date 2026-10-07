# Lab Template — Use for Every Project

## 1. Before coding

Write down:

- inputs
- outputs
- success criteria
- failure criteria
- destructive actions
- assumptions

## 2. First implementation

Aim for a working happy path in 30 minutes. Do not optimize early.

## 3. Test matrix

At minimum:

```text
happy path
empty input
malformed input
missing file/directory
permission problem
unexpected whitespace
special filename/data value
repeat execution
boundary threshold
```

## 4. Improvement pass

Ask:

- What happens if a command fails?
- What happens if one record is malformed?
- What happens if there are no matches?
- What happens if the script is interrupted?
- What can be made configurable?
- Can the destructive parts be previewed first?
- Can logs explain exactly what happened?

## 5. Explanation pass

Be able to explain:

1. control flow;
2. data flow;
3. error handling;
4. safety controls;
5. test strategy;
6. what you would change before production use.
