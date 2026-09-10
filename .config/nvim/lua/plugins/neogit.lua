return {
  {
    "NeogitOrg/neogit",
    dependencies = {
      "nvim-lua/plenary.nvim", -- required
      "sindrets/diffview.nvim", -- optional - Diff integration
      "nvim-telescope/telescope.nvim", -- optional
    },
    integrations = {
      diffview = true,
    },
  },
  {
    "fredehoey/tardis.nvim",
    dependencies = { "nvim-lua/plenary.nvim" },
    config = true,
  },
  { "folke/tokyonight.nvim" },
  {
    "LazyVim/LazyVim",
    opts = {
      colorscheme = "tokyonight",
    },
  },
  {
    "sindrets/diffview.nvim",
  },
}
