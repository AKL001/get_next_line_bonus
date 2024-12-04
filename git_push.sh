#!/bin/bash

# Check if a commit message was provided
if [ -z "$1" ]; then
  echo "Please provide a commit message."
  echo "Usage: ./git_auto_push.sh <commit-message>"
  exit 1
fi

# Get the commit message
commit_message="$1"

# Add all changes to the staging area
git add .

# Commit the changes with the provided message
git commit -m "$commit_message"

# Push the changes to the remote repository
git push origin main  # Replace 'main' with your branch name if needed

# Check if the push was successful
if [ $? -eq 0 ]; then
  echo "Changes have been successfully pushed to GitHub."
else
  echo "An error occurred while pushing changes."
fi

