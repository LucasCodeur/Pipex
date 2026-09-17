# pipex

## Overview

**pipex** is a project from the **42 curriculum** focused on process management, Unix pipes, file descriptors, and program execution.

The goal is to reproduce the behavior of a shell pipeline by connecting multiple processes and redirecting their input and output through Unix pipes.

## Objectives

* Work with Unix pipes.
* Manipulate file descriptors.
* Create and manage processes.
* Use `fork()` and `execve()` to execute external programs.
* Implement input and output redirections.
* Search for executable commands through the `PATH`.
* Handle errors and invalid inputs.
* Manage dynamically allocated memory correctly.

## Core Concepts

The project involves several fundamental Unix concepts:

* **Processes** and process creation.
* **Pipes** for inter-process communication.
* **File descriptors** and redirections.
* **`fork()`** for creating child processes.
* **`execve()`** for executing programs.
* **`waitpid()`** for process synchronization.
* **Environment variables** and `PATH` resolution.

The main challenge is correctly connecting the standard input and output of different processes so that data can flow through the pipeline as it would in a Unix shell.

## Skills Developed

* **C**
* Unix / Linux
* Process management
* Inter-process communication
* Pipes
* File descriptors
* System calls
* Process synchronization
* Command execution
* Environment variables
* Memory management
* Error handling
* Debugging

## What I Learned

pipex gave me a deeper understanding of how Unix processes communicate and how shell pipelines work internally.

The project helped me understand the relationship between **processes, file descriptors, pipes, and program execution**, while developing a more practical understanding of Unix system calls.

It also provided a foundation for more advanced system programming and network-related projects.

---

# pipex

## Présentation

**pipex** est un projet du cursus **42** axé sur la gestion des processus, les pipes Unix, les descripteurs de fichiers et l’exécution de programmes.

L’objectif est de reproduire le fonctionnement d’un pipeline shell en connectant plusieurs processus et en redirigeant leurs entrées et sorties à travers des pipes Unix.

## Objectifs

* Manipuler les pipes Unix.
* Manipuler les descripteurs de fichiers.
* Créer et gérer des processus.
* Utiliser `fork()` et `execve()` pour exécuter des programmes externes.
* Implémenter les redirections d’entrée et de sortie.
* Rechercher les commandes exécutables à travers le `PATH`.
* Gérer les erreurs et les entrées invalides.
* Gérer correctement la mémoire allouée dynamiquement.

## Concepts principaux

Le projet permet de travailler plusieurs concepts fondamentaux d’Unix :

* **Processus** et création de processus.
* **Pipes** pour la communication inter-processus.
* **Descripteurs de fichiers** et redirections.
* **`fork()`** pour créer des processus fils.
* **`execve()`** pour exécuter des programmes.
* **`waitpid()`** pour synchroniser les processus.
* **Variables d’environnement** et résolution du `PATH`.

Le principal défi consiste à connecter correctement les entrées et sorties standard des différents processus afin que les données circulent dans le pipeline comme dans un shell Unix.

## Compétences développées

* **C**
* Unix / Linux
* Gestion des processus
* Communication inter-processus
* Pipes
* Descripteurs de fichiers
* Appels système
* Synchronisation des processus
* Exécution de commandes
* Variables d’environnement
* Gestion de la mémoire
* Gestion des erreurs
* Debugging

## Ce que j’ai appris

pipex m’a permis de mieux comprendre la communication entre les processus Unix et le fonctionnement interne des pipelines shell.

Le projet m’a notamment permis de comprendre les interactions entre **processus, descripteurs de fichiers, pipes et exécution de programmes**, tout en développant une compréhension plus concrète des appels système Unix.

Il constitue également une bonne base pour des projets plus avancés en programmation système et réseau.
