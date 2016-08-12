/*
  Name: David Amante
  Created: 12 August 2016
  Project: Make a program that converts decimal to binary.
    Try to include these others too:
      - binary to decimal
      - binary to octal
      - decimal to hexacdecimal
      - decimal to octal
      - hexadecimal to decimal
      - hexadecimal to octal
*/


import java.util.Scanner;

public class DectoBin {
  public static void main(String args[])
  {
    Scanner input = new Scanner(System.in);
    String binary = "";
    int decimal;
    System.out.print("Enter the decimal you want to convert to binary: ");
    decimal = input.nextInt();

    if(decimal - 128 >= 0)
    {
      binary += "1";
      decimal -= 128;
    }
    else
    {
      binary += "0";
    }

    if(decimal - 64 >= 0)
    {
      binary += "1";
      decimal -= 64;
    }
    else
    {
      binary += "0";
    }

    if(decimal - 32 >= 0)
    {
      binary += "1";
      decimal -= 32;
    }
    else
    {
      binary += "0";
    }

    if(decimal - 16 >= 0)
    {
      binary += "1";
      decimal -= 16;
    }
    else
    {
      binary += "0";
    }

    if(decimal - 8 >= 0)
    {
      binary += "1";
      decimal -= 8;
    }
    else
    {
      binary += "0";
    }
    if(decimal - 4 >= 0)
    {
      binary += "1";
      decimal -= 4;
    }
    else
    {
      binary += "0";
    }
    if(decimal - 2 >= 0)
    {
      binary += "1";
      decimal -= 2;
    }
    else
    {
      binary += "0";
    }
    if(decimal - 1 >= 0)
    {
      binary += "1";
      decimal -= 1;
    }
    else
    {
      binary += "0";
    }

    System.out.print(binary);
  }
}
