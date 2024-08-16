{
  description = "A Nix-flake-based OI environment";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
    luogu-gcc.url = "github:luogu-dev/judge-env";
  };

  outputs = { self , nixpkgs, luogu-gcc ,... }: let
    system = "x86_64-linux";
  in {
    devShells."${system}".default = let
      pkgs = import nixpkgs {
        inherit system;
      };
    in pkgs.mkShell {
      packages = with pkgs; [
        luogu-gcc.packages.${system}.gcc-930
      ];

      shellHook = ''
        zsh
      '';
    };
  };
}
