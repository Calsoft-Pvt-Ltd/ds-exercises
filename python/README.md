# Python Exercises

## Setup

From the `python/` directory:

```bash
# 1. Create a virtual environment
python3 -m venv .venv

# 2. Activate it
source .venv/bin/activate        # macOS / Linux
# .venv\Scripts\activate         # Windows

# 3. Install dependencies
pip install -r requirements.txt
```

You should see `(.venv)` in your prompt when the environment is active.

To deactivate when you're done:
```bash
deactivate
```

## Running Tests

Run all tests:
```bash
pytest tests/ -v
```

Run a single exercise's tests:
```bash
pytest tests/test_array.py -v
pytest tests/test_linked_list.py -v
pytest tests/test_stack.py -v
pytest tests/test_queue.py -v
```

## Workflow

1. Create a feature branch: `git checkout -b feature/<your-name>`
2. Implement the methods marked with `# TODO: implement this`
3. Run tests locally until all pass
4. Push your branch: `git push -u origin feature/<your-name>`

## Files to Edit

Only edit files inside `exercises/`. Do **not** modify anything in `tests/`.

```
python/
├── exercises/
│   ├── array_exercise.py        ← edit this
│   ├── linked_list_exercise.py  ← edit this
│   ├── stack_exercise.py        ← edit this
│   └── queue_exercise.py        ← edit this
└── tests/
    ├── test_array.py
    ├── test_linked_list.py
    ├── test_stack.py
    └── test_queue.py
```
