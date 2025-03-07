```markdown
# SuperFetch

SuperFetch is a lightweight alternative to NeoFetch for Windows, written in C. It displays system information such as computer name, CPU architecture, core count, RAM details, and GPU model.

## Features
- Displays essential system information
- Shows CPU core count
- Reports total and available RAM
- Detects GPU model
- ASCII logo

## Installation
### 1. Install via Git
Open Command Prompt (cmd) or PowerShell and run:
```sh
git clone https://github.com/your-username/SuperFetch.git
cd SuperFetch
```

### 2. Compilation
Compile the program using MinGW or MSVC.

#### MinGW (GCC)
```sh
gcc -o superfetch superfetch.c -Wall
```

#### MSVC (cl.exe)
```sh
cl superfetch.c
```

### 3. Running the Program
After compilation, run:
```sh
./superfetch
```

## Future Plans
- Add CPU load monitoring
- Display CPU and GPU temperature
- Show OS version
- Improve ASCII art

## License
This project is licensed under the Apache License 2.0.
```

