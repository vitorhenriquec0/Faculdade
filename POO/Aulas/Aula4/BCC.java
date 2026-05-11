package POO.Aulas.Aula4;

import POO.Aulas.Aula4.entities2.*;

import java.util.ArrayList;
import java.util.Scanner;

public class BCC {

	private static int lerInteiro(Scanner scanner, String mensagem) {
		while (true) {
			System.out.print(mensagem);
			String entrada = scanner.nextLine();
			try {
				return Integer.parseInt(entrada);
			} catch (NumberFormatException e) {
				System.out.println("Opcao invalida. Tente novamente.");
			}
		}
	}

	private static Disciplina buscarDisciplina(ArrayList<Disciplina> disciplinas, String nome) {
		for (Disciplina disciplina : disciplinas) {
			if (disciplina.getNomeDisciplina().equalsIgnoreCase(nome)) {
				return disciplina;
			}
		}
		return null;
	}

	private static Aluno buscarAluno(ArrayList<Aluno> alunos, String nome) {
		for (Aluno aluno : alunos) {
			if (aluno.getNome().equalsIgnoreCase(nome)) {
				return aluno;
			}
		}
		return null;
	}

	private static void exibirDiasSemana() {
		System.out.println("Dias disponiveis:");
		Pessoa.DiasSemana[] dias = Pessoa.DiasSemana.values();
		for (int i = 0; i < dias.length; i++) {
			System.out.println((i + 1) + " - " + dias[i].getDescricao());
		}
	}

	private static void exibirHorarios() {
		System.out.println("Horarios disponiveis:");
		System.out.println("1 - 8h");
		System.out.println("2 - 10h");
		System.out.println("3 - 14h");
		System.out.println("4 - 16h");
	}

	private static void exibirHorariosLivres(Semestre semestre, int dia) {
		System.out.println("Horarios livres para " + Pessoa.DiasSemana.values()[dia - 1].getDescricao() + ":");
		boolean encontrou = false;
		for (int horario = 1; horario <= 4; horario++) {
			if (semestre.horarioDisponivel(dia, horario)) {
				System.out.println(horario + " - " + (horario == 1 ? "8h" : horario == 2 ? "10h" : horario == 3 ? "14h" : "16h"));
				encontrou = true;
			}
		}
		if (!encontrou) {
			System.out.println("Nenhum horario livre nesse dia.");
		}
	}

	private static int lerDiaValido(Scanner scanner, String mensagem) {
		while (true) {
			int dia = lerInteiro(scanner, mensagem);
			if (dia >= 1 && dia <= 5) {
				return dia;
			}
			System.out.println("Dia invalido. Use um valor de 1 a 5.");
		}
	}

	private static int lerHorarioLivre(Scanner scanner, String mensagem, Semestre semestre, int dia) {
		while (true) {
			int horario = lerInteiro(scanner, mensagem);
			if (horario < 1 || horario > 4) {
				System.out.println("Horario invalido. Use um valor de 1 a 4.");
				continue;
			}
			if (!semestre.horarioDisponivel(dia, horario)) {
				System.out.println("Esse horario ja esta ocupado nesse dia. Escolha outro.");
				continue;
			}
			return horario;
		}
	}

	public static void main(String[] args) {
        /*
		Semestre semestre2026_1 = new Semestre("2026.1");

		Disciplina poo = new Disciplina("POO", "Prof. Dr. Guilherme Freire", 2, 1);
		Disciplina ed1 = new Disciplina("ED1", "Prof. Dr. Wallace Correa", 3, 2);
		Disciplina algebra = new Disciplina("Algebra Linear", "Prof. Dr. Weber", 4, 1);
		Disciplina linguagens = new Disciplina("Linguagens de Programação", "Prof. Dr. Arnaldo", 5, 3);
		Disciplina progcompetitiva = new Disciplina("Programação Competitiva", "Prof. Dr. Aleardo", 2, 1);

		semestre2026_1.adicionarDisciplina(poo);
		semestre2026_1.adicionarDisciplina(ed1);
		semestre2026_1.adicionarDisciplina(algebra);
		semestre2026_1.adicionarDisciplina(linguagens);
		semestre2026_1.adicionarDisciplina(progcompetitiva);

		Aluno vitor = new Aluno("Vitor", 19, 'M', 0, 9.5);
		Aluno mariana = new Aluno("Mariana", 20, 'F', 0, 9.1);

		semestre2026_1.matricularAlunoEmDisciplina(vitor, poo);
		semestre2026_1.matricularAlunoEmDisciplina(vitor, ed1);
		semestre2026_1.matricularAlunoEmDisciplina(vitor, algebra);

		semestre2026_1.matricularAlunoEmDisciplina(mariana, poo);
		semestre2026_1.matricularAlunoEmDisciplina(mariana, linguagens);

		System.out.println();
		semestre2026_1.exibirDisciplinas();
		System.out.println();
		semestre2026_1.exibirAlunosPeriodo();

		System.out.println("\nDisciplinas de " + vitor.getNome() + ": " + vitor.getDisciplinas().size());
		vitor.exibirMatrizHoraria();

        */

		Scanner scanner = new Scanner(System.in);
		ArrayList<Disciplina> disciplinas = new ArrayList<>();
		ArrayList<Aluno> alunos = new ArrayList<>();
		Semestre semestre = new Semestre("2026.1");

		int opcao = -1;
		while (opcao != 0) {
			System.out.println("\n=== BCC ===");
			System.out.println("1 - Criar semestre");
			System.out.println("2 - Cadastrar disciplina");
			System.out.println("3 - Cadastrar aluno");
			System.out.println("4 - Matricular aluno em disciplina");
			System.out.println("5 - Listar disciplinas");
			System.out.println("6 - Listar alunos do periodo");
			System.out.println("7 - Exibir matriz horaria de um aluno");
			System.out.println("0 - Sair");
			opcao = lerInteiro(scanner, "Escolha uma opcao: ");

			switch (opcao) {
				case 1:
					System.out.print("Periodo do semestre: ");
					String periodo = scanner.nextLine();
					semestre = new Semestre(periodo);
					disciplinas.clear();
					alunos.clear();
					System.out.println("Semestre criado: " + periodo);
					break;
				case 2:
					System.out.print("Nome da disciplina: ");
					String nomeDisciplina = scanner.nextLine();
					System.out.print("Professor: ");
					String professor = scanner.nextLine();
					int quantidadeEncontros = lerInteiro(scanner, "Quantos encontros esta disciplina tera? ");
					if (quantidadeEncontros <= 0) {
						System.out.println("A disciplina precisa de pelo menos um encontro.");
						break;
					}
					exibirDiasSemana();
					int dia = lerDiaValido(scanner, "Dia do primeiro encontro: ");
					exibirHorariosLivres(semestre, dia);
					int horario = lerHorarioLivre(scanner, "Horario do primeiro encontro: ", semestre, dia);
					Disciplina disciplina = new Disciplina(nomeDisciplina, professor, dia, horario);
					for (int i = 2; i <= quantidadeEncontros; i++) {
						System.out.println("\nCadastro do encontro " + i + ":");
						exibirDiasSemana();
						int diaExtra = lerDiaValido(scanner, "Dia do encontro " + i + ": ");
						exibirHorariosLivres(semestre, diaExtra);
						int horarioExtra = lerHorarioLivre(scanner, "Horario do encontro " + i + ": ", semestre, diaExtra);
						if (!disciplina.adicionarHorarioAula(diaExtra, horarioExtra)) {
							System.out.println("Encontro repetido ou invalido. Tente novamente.");
							i--;
						}
					}
					if (semestre.adicionarDisciplina(disciplina)) {
						disciplinas.add(disciplina);
					}
					break;
				case 3:
					System.out.print("Nome do aluno: ");
					String nomeAluno = scanner.nextLine();
					int idade = lerInteiro(scanner, "Idade: ");
					System.out.print("Sexo (M/F): ");
					char sexo = scanner.nextLine().toUpperCase().charAt(0);
					int faltas = lerInteiro(scanner, "Faltas: ");
					System.out.print("Media: ");
					Double media = Double.parseDouble(scanner.nextLine());
					Aluno aluno = new Aluno(nomeAluno, idade, sexo, faltas, media);
					alunos.add(aluno);
					System.out.println("Aluno cadastrado com sucesso.");
					break;
				case 4:
					System.out.print("Nome do aluno: ");
					Aluno alunoMatricula = buscarAluno(alunos, scanner.nextLine());
					if (alunoMatricula == null) {
						System.out.println("Aluno nao encontrado.");
						break;
					}
					System.out.print("Nome da disciplina: ");
					Disciplina disciplinaMatricula = buscarDisciplina(disciplinas, scanner.nextLine());
					if (disciplinaMatricula == null) {
						System.out.println("Disciplina nao encontrada.");
						break;
					}
					semestre.matricularAlunoEmDisciplina(alunoMatricula, disciplinaMatricula);
					break;
				case 5:
					semestre.exibirDisciplinas();
					break;
				case 6:
					semestre.exibirAlunosPeriodo();
					break;
				case 7:
					System.out.print("Nome do aluno: ");
					Aluno alunoMatriz = buscarAluno(alunos, scanner.nextLine());
					if (alunoMatriz == null) {
						System.out.println("Aluno nao encontrado.");
						break;
					}
					alunoMatriz.exibirMatrizHoraria();
					break;
				case 0:
					System.out.println("Encerrando sistema.");
					break;
				default:
					System.out.println("Opcao invalida.");
			}
		}

		scanner.close();
	}

}
