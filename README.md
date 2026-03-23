# Calsoft Engineering Internship 2026 — Session Code Repository

This repository contains code samples, starter files, exercises and
problem statements for the Calsoft Engineering Internship Program 2026.

---

## Repository Structure

```
Interns_Training_2026/
├── sessions/
│   ├── Programming-Logic/
│   ├── Design/
│   ├── DSA/
│   ├── Domain/
│   │   ├── cloud/
│   │   ├── dataprotection/
│   │   ├── devops/
│   │   ├── networking/
│   │   ├── quality-engineering/
│   │   ├── security/
│   │   ├── storage/
│   │   ├── Telco/
│   │   └── virtualization/
│   ├── Capstone/
│   └── Hackathon/
└── README.md
```

---

## For Interns

### Step 1 — Fork this repository
- Click **Fork** at the top right of this page
- This creates your own personal copy of the repo under your GitHub account

### Step 2 — Clone your fork locally
```
git clone https://github.com/<your-username>/Interns_Training_2026.git
cd Interns_Training_2026
```

### Step 3 — Connect to the main repo
Run this once after cloning:
```
git remote add upstream https://github.com/Calsoft-Pvt-Ltd/Interns_Training_2026.git
```

### Step 4 — Pull session files before every session
At the start of each session, run:
```
git fetch upstream
git merge upstream/main
```
This pulls the latest session files the trainer has just pushed.

### Step 5 — Do your work
Work inside the relevant session folder. Do not modify files outside your session folder.

### Step 6 — Submit your work via Pull Request
```
git add .
git commit -m "s01-programming-logic — <your-name> submission"
git push origin main
```
Then go to your fork on GitHub → click **Contribute** → **Open Pull Request** → add your name in the title → Submit.

### Commit message format
```
<session-folder> — <your-name> — <brief description>
```
Example:
```
s03-DSA — Rehan Farooque — binary search implementation
```

---

## For Trainers

### Push rule
Push your session files **on the morning of your session. Not before.**
Interns pull at the start of the session — anything pushed early is visible early.

### Where to push
Push only inside your designated session folder. Do not push to other session folders. <trainer names are listed only for reference>

| Session Folder                      | Topic                          | Trainer        |
| ----------------------------------- | ------------------------------ | -------------- |
| sessions/Programming-Logic          | Programming Logic              | Ram            |
| sessions/Design                     | Software Design                | Amit           |
| sessions/DSA                        | Data Structures and Algorithms | Ashwin Bhide   |
| sessions/Domain/storage             | Storage                        | Akshay         |
| sessions/Domain/virtualization      | Virtualization                 | [Satybhan      |
| sessions/Domain/cloud               | Cloud                          | Rajshekhar     |
| sessions/Domain/networking          | Networking                     | Surendra       |
| sessions/Domain/devops              | DevOps                         | Brajesh        |
| sessions/Domain/security            | Security                       | Suresh Patidar |
| sessions/Domain/quality-engineering | Quality Engineering            | Sujit          |
| sessions/Domain/dataprotection      | Data Protection                | Helina         |
| sessions/Domain/Telco               | Telco                          | Surendra       |
| sessions/Capstone                   | Capstone Project               | [Trainer Name] |
| sessions/Hackathon                  | Hackathon                      | [Trainer Name] |

### How to push your session files
```
git add sessions/<your-session-folder>/
git commit -m "<session-folder> — session files added"
git push origin main
```

### Reviewing intern submissions
- Go to the **Pull Requests** tab on the main repo
- Open the intern's PR
- Review the code and leave inline comments
- Request changes or Approve
- Do not merge — submissions are for review only

---

## Rules

- Interns do not push directly to this repository
- All intern submissions come in via Pull Requests only
- Trainers push only to their own session folder
- Problem statements and answer keys are on SharePoint — not in this repository

---

*Calsoft Confidential — Internal use only*
```

