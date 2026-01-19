#!/bin/bash

declare -A resultArray

ROW_LENGTH=63
COLUMN_LENGTH=100
INITIAL_LENGTH=16
START_COL=$((COLUMN_LENGTH / 2 - 1))

draw_fractal() {
    local iterations=$1
    local row=$2
    local col=$3
    local length=$4

    if (( iterations == 0 )); then
        return
    fi

    for (( r = 0; r < length; r++ )); do
        resultArray[$((row - r)),$col]="1"
    done

    local branch_start_row=$((row - length))
    for (( c = 1; c <= length; c++ )); do
        resultArray[$((branch_start_row - c + 1)),$((col - c))]="1"
        resultArray[$((branch_start_row - c + 1)),$((col + c))]="1"
    done
    
    local next_iterations=$((iterations - 1))
    local next_length=$((length / 2))
    local next_row=$((branch_start_row - length))

    draw_fractal "$next_iterations" "$next_row" "$((col - length))" "$next_length"
    draw_fractal "$next_iterations" "$next_row" "$((col + length))" "$next_length"
}

read N

for (( r = 0; r < ROW_LENGTH; r++ )); do
    for (( c = 0; c < COLUMN_LENGTH; c++ )); do
        resultArray[$r,$c]="_"
    done
done

draw_fractal "$N" "$((ROW_LENGTH - 1))" "$START_COL" "$INITIAL_LENGTH"

for (( r = 0; r < ROW_LENGTH; r++ )); do
    for (( c = 0; c < COLUMN_LENGTH; c++ )); do
        printf "%s" "${resultArray[$r,$c]}"
    done
    echo ""
done
