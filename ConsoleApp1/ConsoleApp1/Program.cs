using System.Globalization;
using System.Runtime.CompilerServices;
using System.Runtime.Serialization;
using System.Security.Cryptography.X509Certificates;
using System.Xml.Linq;

namespace ConsoleApp1
{
    internal class Program
    {
        public static unsafe void PlaceCursor((int, int) point)
        {
            Console.SetCursorPosition(point.Item1, point.Item2);
            int x = 0;
            _ = 0;
            
            int* y = &x;

        }

        static void Main(string[] args)
        {
            GameGrid gameGrid = new GameGrid();
            gameGrid.PopulateGridInfo();
            gameGrid.DrawGrid();
            Zblock zblock = new Zblock();
            zblock.AssignCoordinates();
            //zblock.RotateRight();
            zblock.DrawBlock(gameGrid);
            while (true)
            {
                var key = Console.ReadKey().Key;
                switch (key)
                {
                    case ConsoleKey.UpArrow:
                        zblock.RotateRight(gameGrid);
                        break;
                    case ConsoleKey.RightArrow:
                        bool check = false ;
                        for (int i = 0; i < 4; i++)
                        {
                            (int, int) temp = zblock.blockCoordinates[(3, i)].coorVector;
                            if (zblock.blockCoordinates[(3, i)].piecePlacement == gameGrid.GameGridCoordinates[temp].isEmpty)
                            {
                                check = true;
                            }
                        }
                        if (!check)
                        {
                            zblock.MoveRight(1, gameGrid);
                        }
                        break;
                    case ConsoleKey.LeftArrow:
                        check = false;
                        int colomn = zblock.IsColumnEmpty();
                        switch (colomn)
                        {
                            case 0:
                                for (int i = 0; i < 4; i++)
                                {
                                    //(int, int) temp = zblock.blockCoordinates[(0, i)].coorVector;
                                    //temp.Item1--;
                                    //PlaceCursor(temp);
                                    //if (gameGrid.GameGridCoordinates[temp].isEmpty)
                                    //{
                                    //    check = true;
                                    //}
                                }
                                break;
                            case 1:

                                (int, int) temp = zblock.blockCoordinates[(1, 1)].coorVector;
                                temp.Item1--;
                                temp.Item1--;
                                if (gameGrid.GameGridCoordinates[temp].isEmpty)
                                {
                                    check = true;
                                    if()
                                }
                                else
                                {
                                    check = true;
                                    if (zblock.blockCoordinates[(0, 0)].coorVector.gameGridX == 4)
                                    {
                                        check = false;
                                    }
                                }
                                break;
                        }

                        if (check)
                        {
                            zblock.MoveRight(-1, gameGrid);
                        }
                        break;
                    case ConsoleKey.DownArrow:
                        zblock.MoveDown(gameGrid);
                        break;
                    case ConsoleKey.Spacebar: 
                        zblock.RotateLeft(gameGrid);
                        break;
                    default:
                        break;
                }
            }

        }
    }
    public class Zblock
    {
        public (int X, int Y)[,] preImage = new (int, int)[4, 4];
        public (int X, int Y)[,] Image = new (int, int)[4, 4];
        public Dictionary<(int X, int Y), ((int gameGridX, int gameGridY) coorVector, bool piecePlacement)> blockCoordinates = new Dictionary<(int, int), ((int, int), bool)>();
        public static ((int Y, int X), bool)[] state1 = new ((int, int), bool)[4]
        {
            ((0,0), true),
            ((1,0), true),
            ((1,1), true),
            ((2,1), true),

        };
        public static ((int, int), bool)[] state2 = new ((int, int), bool)[4]
        {
            ((2, 0), true),
            ((1, 1), true),
            ((2, 1), true),
            ((1, 2), true)
        };
        public static ((int, int), bool)[] state3 = new ((int, int), bool)[4]
        {
            ((0, 1), true),
            ((1, 1), true),
            ((1, 2), true),
            ((2, 2), true)
        };
        public static ((int, int), bool)[] state4 = new ((int, int), bool)[4]
        {
            ((1, 0), true),
            ((0, 1), true),
            ((1, 1), true),
            ((0, 2), true)
        };
        public int index = 0; 
        public ((int , int)gridTuple, bool)[][] states = new ((int, int), bool)[][] { state1,state2,state3,state4};
        public void AssignCoordinates()
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    preImage[i, j] = (i, j);
                    Image[i, j] = (i + 11, j + 1);
                }
            }

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    blockCoordinates.Add(preImage[j, i], (Image[j, i], false));
                }
            }
            DefaultState();
        }
        public int IsColumnEmpty()
        {
            bool check = false;
            //int column = 0;
            for(int i = 0;i < 4; i++)
            {
                if(blockCoordinates[(0, i)].piecePlacement)
                {
                    check = true;
                    break;
                }
            }
            if (check)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        public void DefaultState()
        {
            foreach(var x in state1)
            {
                blockCoordinates[x.Item1] = (Image[x.Item1.Y,x.Item1.X],true);
            }
        }
        public void DrawBlock(GameGrid gameGrid)
        {
            
            foreach (var x in blockCoordinates)
            {
                
                if (x.Value.Item2)
                {
                    Console.BackgroundColor = ConsoleColor.Green;
                    Console.ForegroundColor = ConsoleColor.Green;
                    Program.PlaceCursor((0, 0));
                    Console.Write(x.Value.Item1.ToString());
                    Program.PlaceCursor(x.Value.Item1); 
                    Console.Write("0");
                    Console.ResetColor();
                }
                else 
                {
                    if (!gameGrid.GameGridCoordinates[x.Value.coorVector].isEmpty)
                    {
                        Console.BackgroundColor = gameGrid.GameGridCoordinates[(5,5)].colour;
                        Program.PlaceCursor(x.Value.coorVector);
                        Console.Write("0");
                    }
                    else
                    {
                        Console.ResetColor();
                        Program.PlaceCursor((0, 0));
                        Console.Write(x.Value.Item1.ToString());
                        Program.PlaceCursor(x.Value.Item1);
                        Console.Write("-");
                    }

                }
            }
        }
        public void DisplayDict()
        {
            foreach(var x in blockCoordinates)
            {
                Console.WriteLine(x.Key.ToString() + " : " + x.Value.Item1.ToString() + x.Value.Item2.ToString());
            }
        }
        public void MoveRight(int step,GameGrid gameGrid)
        {
            ClearBlock(gameGrid);
            HorizontalShift(step);
            DrawBlock(gameGrid);
        }

        public void ClearBlock(GameGrid gameGrid)
        {
            foreach(var x in blockCoordinates)
            {
                if (gameGrid.GameGridCoordinates[x.Value.coorVector].isEmpty)
                {
                    Console.ResetColor();
                    Program.PlaceCursor(x.Value.Item1);
                    Console.Write(" ");
                }
                else
                {
                    Program.PlaceCursor(x.Value.coorVector);
                    (int, int) temp = x.Value.coorVector;
                    Console.BackgroundColor = gameGrid.GameGridCoordinates[temp].colour;
                    Console.ForegroundColor = gameGrid.GameGridCoordinates[x.Value.coorVector].colour;
                }
            }
        }
        public void HorizontalShift(int value)
        {
            foreach (var x in blockCoordinates.Keys)
            {
                blockCoordinates[x] = ((blockCoordinates[x].Item1.Item1 + value, blockCoordinates[x].Item1.Item2), blockCoordinates[x].Item2);
            }
        }
        public void VerticalShift(int value)
        {
            foreach (var x in blockCoordinates.Keys)
            {
                blockCoordinates[x] = ((blockCoordinates[x].coorVector.gameGridX , blockCoordinates[x].coorVector.gameGridY + value), blockCoordinates[x].piecePlacement);
            }
        }
        public void MoveDown(GameGrid gameGrid)
        {
            ClearBlock(gameGrid);
            VerticalShift(1);
            DrawBlock(gameGrid);
        }
        public void RotateLeft(GameGrid gameGrid)
        {
            if(index < 3)
            {
                index++;
            }
            else 
            {
                index = 0;
            }
            Rotate(index);
            DrawBlock(gameGrid);
        }
        public void RotateRight(GameGrid gameGrid)
        {
            if (index > 0)
            {
                index--;
            }
            else
            {
                index = 3;
            }
            Rotate(index);
            DrawBlock(gameGrid);
        }
        public void Rotate(int i)
        {
            foreach(var x in blockCoordinates.Keys)
            {
                blockCoordinates[x] = (blockCoordinates[x].coorVector, false);
            }
            foreach (var x in states[i])
            {
                blockCoordinates[x.gridTuple] = (blockCoordinates[x.gridTuple].coorVector, true);
            }
        }
        
    }
    public class GameGrid
    {
        public (int, int)[,] coordinates = new (int, int)[22, 25];
        public Dictionary<(int gameGridX, int GameGridY),(bool isEmpty ,ConsoleColor colour) > GameGridCoordinates = new Dictionary<(int, int), (bool, ConsoleColor)>();
        public void PopulateGridInfo()
        {
            for (int i = 0; i < 22; i++)
            {
                for (int j = 0; j < 25; j++)
                {
                    coordinates[i, j] = (i + 4, j);
                }
            }

            for (int i = 0; i < 25; i++)
            {
                for (int j = 0; j < 22; j++)
                {

                    GameGridCoordinates.Add(coordinates[j, i], (true,ConsoleColor.White));
                }
            }
            for(int i = 0;i <= 25; i++)
            {
                GameGridCoordinates[(5, i)] = (false,ConsoleColor.White);
                GameGridCoordinates[(20,i)] = (false, ConsoleColor.White);
            }
            for (int i = 5; i <= 20; i++)
            {
                GameGridCoordinates[(i, 0)] = (false, ConsoleColor.White);
                GameGridCoordinates[(i, 25)] = (false, ConsoleColor.White);
            }
        }
        public void DrawGrid()
        {
            foreach(var cell in GameGridCoordinates)
            {
                if (!cell.Value.isEmpty)
                {
                    Program.PlaceCursor(cell.Key);
                    Console.BackgroundColor = cell.Value.colour;
                    Console.WriteLine("0");
                }
            }
        }

    }
}