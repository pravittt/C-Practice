import sys
import subprocess

def main():
    print("This is the transfer script! ")
    if len(sys.argv) != 2:
        print("Usage: python script.py <file_name>")
        sys.exit(1)

    file_name = sys.argv[1]
    destination = "debian@192.168.2.208:~/"

    try:
        subprocess.run(["scp", file_name, destination], check=True)
        print(f"File {file_name} successfully copied to {destination}")
    except subprocess.CalledProcessError as e:
        print(f"Error occurred while copying file: {e}")

if __name__ == "__main__":
    main()