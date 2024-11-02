const ROWS = 10;
const COLS = 10;

let grid = [
    ['S', '.', '.', '.', '#', '.', '.', '.', '.', 'E'],
    ['.', '#', '#', '.', '.', '#', '.', '#', '.', '.'],
    ['.', '.', '#', '.', '.', '#', '.', '.', '.', '.'],
    ['.', '.', '.', '.', '#', '#', '.', '#', '.', '.'],
    ['.', '#', '.', '.', '.', '.', '#', '.', '.', '.'],
    ['.', '#', '#', '#', '.', '.', '#', '#', '#', '.'],
    ['.', '.', '.', '#', '.', '.', '.', '.', '.', '.'],
    ['.', '#', '.', '.', '#', '#', '.', '#', '.', '.'],
    ['.', '.', '.', '#', '.', '.', '.', '.', '#', '.'],
    ['.', '.', '.', '.', '.', '.', '.', '.', '.', '.']
];

let playerPos = { x: 0, y: 0 };
let steps = 0;

function drawGrid() {
    const gridElement = document.getElementById('grid');
    gridElement.innerHTML = '';

    for (let i = 0; i < ROWS; i++) {
        for (let j = 0; j < COLS; j++) {
            const cell = document.createElement('div');
            cell.classList.add('cell');

            if (grid[i][j] === 'S') cell.classList.add('start');
            else if (grid[i][j] === 'E') cell.classList.add('end');
            else if (grid[i][j] === '#') cell.classList.add('obstacle');
            else if (i === playerPos.x && j === playerPos.y) cell.classList.add('player');

            gridElement.appendChild(cell);
        }
    }

    document.getElementById('stepCounter').textContent = steps;
}

function movePlayer(direction) {
    let newX = playerPos.x;
    let newY = playerPos.y;

    if (direction === 'w') newX--;
    else if (direction === 's') newX++;
    else if (direction === 'a') newY--;
    else if (direction === 'd') newY++;

    if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && grid[newX][newY] !== '#') {
        playerPos.x = newX;
        playerPos.y = newY;
        steps++;

        if (grid[newX][newY] === 'E') {
            alert("Congratulations! You've reached the end! Total steps taken: " + steps);
            playerPos = { x: 0, y: 0 };
            steps = 0;
        }
    }

    drawGrid();
}

document.addEventListener('keydown', (event) => {
    if (['w', 'a', 's', 'd'].includes(event.key)) {
        movePlayer(event.key);
    }
});

drawGrid();

