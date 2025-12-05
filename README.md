# 🧪 CPP Module 00 Tester

<div align="center">

![C++](https://img.shields.io/badge/C++-17-blue.svg?style=flat&logo=c%2B%2B)
![Testing](https://img.shields.io/badge/Testing-Google%20Test-green.svg?style=flat)
![License](https://img.shields.io/badge/License-MIT-yellow.svg?style=flat)
![42](https://img.shields.io/badge/42-Project-000000?style=flat&logo=42)

**A comprehensive testing suite for 42's CPP Module 00**

[Features](#-features) • [Installation](#-installation) • [Usage](#-usage) • [Requirements](#-requirements) • [Contributing](#-contributing)

</div>

---

## 📋 Table of Contents

- [About](#-about)
- [Features](#-features)
- [Requirements](#-requirements)
- [Installation](#-installation)
- [Usage](#-usage)
- [Project Structure](#-project-structure)
- [Test Coverage](#-test-coverage)
- [Troubleshooting](#-troubleshooting)
- [Contributing](#-contributing)
- [Author](#-author)

---

## 🎯 About

This tester is designed to thoroughly test your **CPP Module 00** exercises from the 42 curriculum. It uses **Google Test** framework to provide comprehensive test coverage with a clean, professional output.

The tester automatically detects which exercises you have completed and runs the appropriate tests, including bonus exercises if present.

---

## ✨ Features

- ✅ **Automated Testing** - Tests all mandatory exercises (ex00, ex01) and bonus (ex02)
- 🎨 **Beautiful UI** - Clean, colorful output with progress indicators
- 🔍 **Detailed Feedback** - Shows exactly what passed/failed with file and line numbers
- 🚀 **Smart Detection** - Automatically detects and skips missing exercises
- 📊 **Statistics** - Displays pass rates and execution times
- 🧹 **Easy Cleanup** - Simple make commands for cleaning
- 💡 **Error Display** - Only shows compilation errors when they occur

---

## 🔧 Requirements

### System Requirements

- **Operating System**: Linux or macOS
- **Compiler**: `c++` (g++ or clang++) with C++17 support
- **Make**: GNU Make

### Dependencies

- **Google Test** (gtest)

#### Installing Google Test

**On Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install libgtest-dev
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp lib/*.a /usr/lib
```

**On macOS (using Homebrew):**
```bash
brew install googletest
```

**On Fedora:**
```bash
sudo dnf install gtest-devel
```

---

## 📥 Installation

1. **Clone the repository** as a sibling to your cpp00 directory:

```bash
cd /path/to/your/project
# Your structure should be:
# project/
# ├── cpp00/        (your exercises)
# └── tester/       (this tester)

git clone https://github.com/yourusername/cpp00-tester.git tester
cd tester
```

**Alternative:** If you want the tester inside cpp00:

```bash
cd /path/to/your/cpp00
git clone https://github.com/yourusername/cpp00-tester.git tester
cd tester
```

Then update the paths in each `tester_exXX/Makefile` to point to `../../exXX/` instead of `../../cpp00/exXX/`.

2. **Verify your project structure**:

Your directory should look like this:

```
your_project/
├── cpp00/                    # Your CPP Module 00 exercises
│   ├── ex00/
│   │   ├── Makefile
│   │   ├── megaphone.cpp
│   │   └── ...
│   ├── ex01/
│   │   ├── Makefile
│   │   ├── Contact.cpp
│   │   ├── PhoneBook.cpp
│   │   └── ...
│   └── ex02/ (optional - bonus)
│       ├── Makefile
│       ├── Account.cpp
│       └── ...
│
└── tester/                   # This tester repository
    ├── Makefile
    ├── run_all.cpp
    ├── README.md
    ├── tester_ex00/
    │   ├── Makefile
    │   └── test_ex00.cpp
    ├── tester_ex01/
    │   ├── Makefile
    │   └── test_ex01.cpp
    └── tester_ex02/ (optional)
        ├── Makefile
        └── test_ex02.cpp
```

**Important:** The tester expects your exercises to be in `../cpp00/ex00/`, `../cpp00/ex01/`, etc.

3. **Configure paths** (if needed):

If your directory structure is different, edit the Makefiles in each tester directory to point to your exercise locations:

```makefile
# In tester_ex00/Makefile, tester_ex01/Makefile, etc.
# Change this line to match your structure:
CPP00_DIR = ../../cpp00
```

---

## 🚀 Usage

### Quick Start

Run all tests with one command:

```bash
make run_all
```

### Available Commands

| Command | Description |
|---------|-------------|
| `make all` | Build all mandatory testers (ex00, ex01) |
| `make bonus` | Build bonus tester (ex02) if available |
| `make run_all` | Build and execute all tests including bonus |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and executables |
| `make re` | Rebuild everything from scratch |
| `make banner` | Display the awesome banner |
| `make help` | Show help menu |

### Running Specific Tests

To test individual exercises:

```bash
# Test only ex00
cd tester_ex00
make
./tester_ex00

# Test only ex01
cd tester_ex01
make
./tester_ex01

# Test bonus (if available)
cd tester_ex02
make
./tester_ex02
```

---

## 📁 Project Structure

```
tester/
├── Makefile                 # Main Makefile with unified runner
├── run_all.cpp             # Unified test runner
├── README.md               # This file
├── tester_ex00/
│   ├── Makefile
│   ├── test_ex00.cpp       # Tests for exercise 00
│   └── utils/              # Helper utilities
├── tester_ex01/
│   ├── Makefile
│   ├── test_ex01.cpp       # Tests for exercise 01
│   └── utils/
└── tester_ex02/            # (Optional - Bonus)
    ├── Makefile
    ├── test_ex02.cpp       # Tests for exercise 02
    └── utils/
```

---

## 🧪 Test Coverage

### Exercise 00: Megaphone
- ✅ No arguments test
- ✅ Single argument test
- ✅ Multiple arguments test
- ✅ Special characters handling
- ✅ Mixed case conversion
- ✅ Whitespace handling

### Exercise 01: PhoneBook
- ✅ ADD command functionality
- ✅ SEARCH command functionality
- ✅ EXIT command functionality
- ✅ Contact storage (max 8 contacts)
- ✅ Contact display formatting
- ✅ Input validation
- ✅ Edge cases (empty fields, overflow)

### Exercise 02 (Bonus): Account Class
- ✅ Account creation
- ✅ Deposit functionality
- ✅ Withdrawal functionality
- ✅ Display functions
- ✅ Static members tracking
- ✅ Log output format verification

---

## 🐛 Troubleshooting

### Common Issues

#### 1. **"Google Test not found"**

**Solution:**
```bash
# Install Google Test (see Requirements section)
# Or check if it's installed:
dpkg -l | grep gtest  # On Ubuntu/Debian
brew list | grep googletest  # On macOS
```

#### 2. **"Make: command not found"**

**Solution:**
```bash
# Install make
sudo apt-get install build-essential  # Ubuntu/Debian
brew install make  # macOS
```

#### 3. **"Cannot find exercise files"**

**Solution:**
- Verify your directory structure matches the expected layout
- Check that you're in the tester directory when running commands
- Edit the Makefiles to adjust paths if your structure is different:

```bash
# Check current structure
ls -la ../cpp00/ex00/
ls -la ../cpp00/ex01/

# If your structure is different, edit tester Makefiles
# Example: If cpp00 is in the same directory as tester
# Edit tester_ex00/Makefile and change:
# CPP00_DIR = ../../cpp00
# to:
# CPP00_DIR = ../cpp00
```

#### 4. **"Compilation failed"**

**Solution:**
- Ensure your exercises compile correctly first
- Check that all required source files are present
- Verify Makefiles in each exercise directory
- Make sure you're using C++17 standard

#### 5. **"Permission denied"**

**Solution:**
```bash
chmod +x tester/tester_ex00/tester_ex00
chmod +x tester/tester_ex01/tester_ex01
chmod +x tester/tester_ex02/tester_ex02
```

#### 6. **"Tests fail but my program works"**

**Solution:**
- Check exact output format (whitespace, newlines, etc.)
- Verify you're following the subject requirements exactly
- Look at the error messages for specific failures
- Compare your output with expected output

### Debug Mode

To see detailed compilation output:

```bash
# Run make in verbose mode
make VERBOSE=1

# Or compile manually
cd tester_ex00
make
```

---

## 🤝 Contributing

Contributions are welcome! If you find bugs or want to add features:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Adding New Tests

To add tests for a specific exercise:

1. Navigate to the appropriate tester directory
2. Edit the test file (e.g., `test_ex00.cpp`)
3. Add your test cases using Google Test syntax
4. Rebuild and test

Example:
```cpp
TEST(ExerciseName, TestCaseName) {
    // Your test code here
    EXPECT_EQ(actual, expected);
}
```

---

## 📝 Notes

- **Bonus exercises** (ex02) are optional and will be skipped if not present
- The tester respects the **42 Norm** and coding standards
- All tests include **memory leak checks** where applicable
- Output formatting may vary slightly based on terminal capabilities

---

## 📜 License

This project is licensed under the MIT License - see the LICENSE file for details.

---

## 👨‍💻 Author

**mhamdali**

- 42 Intra: `mhamdali`
- GitHub: [@mhamdali](https://github.com/mhamdali)

---

## 🌟 Acknowledgments

- Thanks to the 42 Network for the challenging curriculum
- Google Test framework for excellent testing capabilities
- All contributors who help improve this tester
